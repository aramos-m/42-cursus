/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 22:14:33 by aramos-m          #+#    #+#             */
/*   Updated: 2026/07/02 00:12:27 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return ((int)n);
}

static int	parser(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = table->start_time;
		table->philos[i].table = table;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->nb_philo];
		i++;
	}
	return (0);
}

static int	init_mutexes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&table->print_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->meal_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->stop_lock, NULL) != 0)
		return (1);
	return (0);
}

int	init_table(t_table *table, int argc, char **argv)
{
	if (!parser(argc, argv))
		return (printf("Error: arguments must be positive integers\n"), 1);
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->must_eat = -1;
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	if (table->nb_philo < 1 || table->time_to_die < 1
		|| table->time_to_eat < 1 || table->time_to_sleep < 1
		|| (argc == 6 && table->must_eat < 1))
		return (printf("Error: invalid argument values\n"), 1);
	table->stop = 0;
	table->start_time = get_time();
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	table->philos = malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->forks || !table->philos)
		return (printf("Error: malloc failed\n"), 1);
	if (init_mutexes(table))
		return (printf("Error: mutex init failed\n"), 1);
	init_philos(table);
	return (0);
}
