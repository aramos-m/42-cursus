/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi <rdi@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:04:09 by rdi               #+#    #+#             */
/*   Updated: 2023/08/13 20:04:45 by rdi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_last_and_first_row(int x)
{
	int	column_nb;

	column_nb = 0;
	while (column_nb < x)
	{
		if (column_nb == 0 || column_nb == x -1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
		column_nb++;
	}
}

void	ft_medium_row(int x)
{
	int	column_nb;

	column_nb = 0;
	while (column_nb < x)
	{
		if (column_nb == 0 || column_nb == x -1)
		{
			ft_putchar('|');
		}
		else
		{
			ft_putchar(' ');
		}
		column_nb++;
	}
}

void	rush(int x, int y)
{
	int	row_nb;
	int	new_line;

	row_nb = 0;
	new_line = 10;
	while (row_nb < y)
	{
		if (row_nb == 0 || row_nb == y - 1)
		{
			ft_last_and_first_row(x);
		}
		else
		{
			ft_medium_row(x);
		}
		row_nb++;
		write(1, &new_line, 1);
	}
}
