/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:50:31 by clagarci          #+#    #+#             */
/*   Updated: 2023/08/27 19:50:43 by bquilumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	decimals(int uds)
{
	int	j;
	int	dec;

	dec = 1;
	j = 0;
	if (uds == 4 || uds == 5)
		dec = 1000;
	else if (uds == 7 || uds == 8)
		dec = 1000000;
	else
	{
		while (j < uds)
		{
			dec *= 10;
			j++;
		}
	}
	return (dec);
}

int	count_units(int n)
{
	int	num;
	int	units;

	units = 0;
	num = n;
	while (num > 9)
	{
		num /= 10;
		units += 1;
	}
	return (units);
}

int	*two_digits(int n, int *array)
{
	int	i;

	i = 0;
	if (n < 19)
		*array++ = n;
	else
	{
		*array++ = n / 10 * 10;
		if (n % 10 != 0)
			*array++ = n % 10;
	}	
	return (array);
}

int	*exceptions(int ud, int *num, int *arr)
{
	if (ud == 5)
	{
		*arr++ = *num / 100000;
		*arr++ = 100;
		*num %= 100000;
	}
	if (ud == 8)
	{
		*arr++ = *num / 100000000;
		*arr++ = 100;
		*num %= 100000000;
	}
	return (arr);
}

int	*entry(int num)
{
	int	*entries;
	int	units;
	int	aux;
	int	*inicio;

	entries = (int *)malloc(20 * sizeof(int));
	inicio = entries;
	aux = num;
	while (num > 99)
	{
		units = 0;
		units = count_units(num);
		if (units == 5)
			entries = exceptions(5, &num, entries);
		if (units == 8)
			entries = exceptions(8, &num, entries);
		entries = two_digits(num / decimals(units), entries);
		*entries++ = decimals(units);
		num = aux % decimals(units);
	}
	entries = two_digits(num, entries);
	*entries = -1;
	return (inicio);
}
