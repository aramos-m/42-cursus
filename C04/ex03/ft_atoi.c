/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:19:29 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/31 20:24:09 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	number;
	int	sign;
	int	i;

	number = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

/*#include <stdio.h>
int main ()
{
	char c[] ="  ---+--+1234ab567";
	printf("%i", ft_atoi(c));
	return 0;
}*/
