/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bquilumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:54:16 by bquilumb          #+#    #+#             */
/*   Updated: 2023/08/27 21:33:31 by bquilumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	check_dic(char *dic_name, char *dic)
{
	int		file;
	ssize_t	file_bytes;

	file_bytes = 0;
	file = open(dic_name, O_RDONLY);
	file_bytes = read(file, dic, 1000);
	close(file);
	if (file_bytes == 0)
	{
		file = -1;
		write(1, "Dict Error\n", 11);
	}
	return (file);
}

int	ft_atoi(char *str)
{
	int		number;
	int		counter;

	number = 0;
	counter = 0;
	while (*str && number != -1 && counter < 10)
	{
		if (*str < 48 || *str > 57)
			number = -1;
		else
		{
			number *= 10;
			number += *str - '0';
			counter ++;
			str ++;
		}	
	}
	if (number == -1 || *str != '\0')
	{
		number = -1;
		write(1, "Error\n", 6);
	}
	return (number);
}

int	is_value(char c)
{
	int	boolean;

	boolean = 0;
	if ((c < 48 || c > 57) && c != ':' && c != ' ')
		boolean = 1;
	return (boolean);
}

char	*put_str(int number)
{	
	int		num_digits;
	int		temp;
	int		i;
	char	*str;

	num_digits = 1;
	temp = number;
	while (temp >= 10)
	{
		temp /= 10;
		num_digits ++;
	}
	str = (char *)malloc((num_digits + 1) * sizeof(char));
	i = num_digits - 1;
	while (i >= 0)
	{
		str[i] = '0' + (number % 10);
		number /= 10;
		i --;
	}
	str[num_digits] = '\0';
	return (str);
}
/*
int	check_format(char *dic)
{
	int		is_correct;
	char	*aux_str;
	int		is_prefix;
	int		is_val;

	is_correct = 1;
	aux_str = dic;
	is_prefix = 1;
	is_val = 0;
	while (*aux_str && is_correct == 1)
	{
		if (*aux_str == '\n')
			is_prefix = 1;
		if (is_prefix)
		{
			if (is_value(*aux_str))
			{
				is_val = 1;
				is_prefix = 0;
			}
		} 
		else
		{
			if (!is_val && *(aux_str - 1) != '\n')
				is_correct = 0;
		}
		aux_str ++;
	}
	return (is_correct);
}*/
