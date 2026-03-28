/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:59:21 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/16 17:26:03 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_comb(int a, int b, int c, int d)
{
	char	w;
	char	x;
	char	y;
	char	z;

	w = a + '0';
	x = b + '0';
	y = c + '0';
	z = d + '0';
	write(1, &w, 1);
	write(1, &x, 1);
	write(1, &" ", 1);
	write(1, &y, 1);
	write(1, &z, 1);
	if (a == 9 && b == 8 && c == 9 && d == 9)
	{
		return ;
	}
	write (1, &",", 1);
	write (1, &" ", 1);
}

void	print(int a, int b, int c, int d)
{
	while (a <= 9)
	{
		while (b <= 8)
		{
			while (c <= 9)
			{
				while (d <= 9)
				{
					write_comb (a, b, c, d);
					d++;
				}
				d = a;
				c++;
			}
			c = a;
			b++;
		}
		b = a;
		a++;
	}
}	

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = 0;
	b = 0;
	c = 0;
	d = 1;
	print(a, b, c, d);
}

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
