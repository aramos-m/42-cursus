/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:47:08 by aramos-m          #+#    #+#             */
/*   Updated: 2026/07/01 22:33:48 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((long long)timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}

int	is_stopped(t_table *table)
{
	int	stopped;

	pthread_mutex_lock(&table->stop_lock);
	stopped = table->stop;
	pthread_mutex_unlock(&table->stop_lock);
	return (stopped);
}

void	smart_sleep(long long ms, t_table *table)
{
	long long	start;

	start = get_time();
	while (get_time() - start < ms)
	{
		if (is_stopped(table))
			break ;
		usleep(300);
	}
}

void	print_status(t_philo *philo, char *status)
{
	long long	ts;

	pthread_mutex_lock(&philo->table->print_lock);
	if (!is_stopped(philo->table))
	{
		ts = get_time() - philo->table->start_time;
		printf("%lld %d %s\n", ts, philo->id, status);
	}
	pthread_mutex_unlock(&philo->table->print_lock);
}
