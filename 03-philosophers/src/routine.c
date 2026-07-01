/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 23:22:45 by aramos-m          #+#    #+#             */
/*   Updated: 2026/07/02 00:58:19 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
}

static void	eat(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	take_forks(philo);
	pthread_mutex_lock(&table->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&table->meal_lock);
	print_status(philo, "is eating");
	smart_sleep(table->time_to_eat, table);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	think(t_philo *philo)
{
	t_table		*table;
	long long	t_think;

	table = philo->table;
	print_status(philo, "is thinking");
	t_think = table->time_to_die - table->time_to_eat - table->time_to_sleep;
	if (t_think < 0)
		t_think = 0;
	if (table->nb_philo % 2 != 0)
		smart_sleep(t_think / 2 + 1, table);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	if (table->nb_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		while (!is_stopped(table))
			usleep(300);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(table->time_to_eat * 500);
	while (!is_stopped(table))
	{
		eat(philo);
		print_status(philo, "is sleeping");
		smart_sleep(table->time_to_sleep, table);
		think(philo);
	}
	return (NULL);
}
