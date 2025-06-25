/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:19:18 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/25 20:12:58 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_sign(char *input, int *i)
{
	if (input[*i] == '-' || input[*i] == '+')
	{
		if (input[(*i)++] == '-')
			return (-1);
	}
	return (1);
}

void	conditions(char *input, int *i, double *result, double *dot)
{
	if (input[*i] == '.')
	{
		if (*dot != 1)
		{
			*result = NAN;
			return ;
		}
		*dot = 10;
	}
	else if (*dot == 1)
		*result = *result * 10 + (input[*i] - '0');
	else
	{
		*result = *result + (input[*i] - '0') / *dot;
		*dot = *dot * 10;
	}
}

double	atod(char *input)
{
	int		i;
	int		neg;
	double	result;
	double	dot;

	i = 0;
	result = 0;
	dot = 1;
	while ((input[i] >= 9 && input[i] <= 13) || (input[i] == 32))
		i++;
	neg = get_sign(input, &i);
	if (input[i] == '\0')
		return (NAN);
	while ((input[i] >= '0' && input[i] <= '9') || input[i] == '.')
	{
		conditions(input, &i, &result, &dot);
		if (isnan(result))
			return (NAN);
		i++;
	}
	if (input[i] != '\0')
		return (NAN);
	return (result * neg);
}
