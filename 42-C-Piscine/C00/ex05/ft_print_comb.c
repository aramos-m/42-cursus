/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:59:21 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/14 16:27:27 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combination(int a, int b, int c)
{
	char	x;
	char	y;
	char	z;

	x = a + '0';
	y = b + '0';
	z = c + '0';
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, &z, 1);
	if (a == 7 && b == 8 && c == 9)
	{
		return ;
	}
	write (1, &",", 1);
	write (1, &" ", 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				print_combination (a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
