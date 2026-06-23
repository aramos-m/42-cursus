/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 10:30:34 by aramos-m          #+#    #+#             */
/*   Updated: 2026/06/23 10:44:27 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str, int *err)
{
	long	number;
	int		sign;
	int		i;
	int		start;

	number = 0;
	sign = 1;
	i = 0;
	*err = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	start = i;
	while (str[i] >= '0' && str[i] <= '9' && number <= INT_MAX)
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if (i == start || str[i] != '\0'
		|| number * sign > INT_MAX || number * sign < INT_MIN)
		*err = 1;
	return ((int)(number * sign));
}

int	ft_error(const char *msg)
{
	printf("Error: %s\n", msg);
	return (1);
}
