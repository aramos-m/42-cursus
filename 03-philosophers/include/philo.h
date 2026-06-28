/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 21:05:19 by aramos-m          #+#    #+#             */
/*   Updated: 2026/07/01 23:50:34 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_table	t_table;

/*
** Philosophers' structure
**	-id: Philosopher's identifier
**	-meals: Number of times the philosopher ate
**	-timestamp: Timestamp od the last time the philosopher ate
** 	-thread: Pointer to philosopher's thread
** 	-timelock: Mutex which control access to philosopher's timestamp
**	-p: Pointer to program's main struct
*/
typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
}	t_philo;

/*
** Table's structure
**	-nb_philo: Number of philosophers and forks
**	-time_to_die: Number of ms they can go without food before dying
**	-time_to_eat: Number of ms they takes to eat
**	-time_to_sleep: Number of ms they takes to sleep
**	-must_eat: Number of times all philosophers have to eat (optional)
*/
typedef struct s_table
{
	int				nb_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_eat;
	int				stop;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	stop_lock;
	t_philo			*philos;
}	t_table;

/* utils.c */
long long	get_time(void);
void		smart_sleep(long long ms, t_table *table);
int			is_stopped(t_table *table);
void		print_status(t_philo *philo, char *status);

/* init.c */
int			init_table(t_table *table, int argc, char **argv);

/* routine.c */
void		*routine(void *arg);
void		*monitor(void *arg);

#endif
