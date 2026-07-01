/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 21:16:59 by aramos-m          #+#    #+#             */
/*   Updated: 2026/07/01 21:47:05 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	declare_death(t_table *table, int i)
{
	pthread_mutex_lock(&table->print_lock);
	pthread_mutex_lock(&table->stop_lock);
	table->stop = 1;
	pthread_mutex_unlock(&table->stop_lock);
	printf("%lld %d died\n", get_time() - table->start_time,
		table->philos[i].id);
	pthread_mutex_unlock(&table->print_lock);
}

static int	check_philo(t_table *table, int i, int *full)
{
	pthread_mutex_lock(&table->meal_lock);
	if (get_time() - table->philos[i].last_meal > table->time_to_die)
	{
		pthread_mutex_unlock(&table->meal_lock);
		declare_death(table, i);
		return (1);
	}
	if (table->must_eat != -1
		&& table->philos[i].meals_eaten < table->must_eat)
		*full = 0;
	pthread_mutex_unlock(&table->meal_lock);
	return (0);
}

void	*monitor(void *arg)
{
	t_table	*table;
	int		i;
	int		full;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		full = 1;
		while (i < table->nb_philo)
		{
			if (check_philo(table, i, &full))
				return (NULL);
			i++;
		}
		if (table->must_eat != -1 && full)
		{
			pthread_mutex_lock(&table->stop_lock);
			table->stop = 1;
			pthread_mutex_unlock(&table->stop_lock);
			return (NULL);
		}
		usleep(1000);
	}
}
