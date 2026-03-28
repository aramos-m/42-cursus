/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:27:07 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/17 13:48:19 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		first_nb;
	int		last_nb;
	char	c;

	while (nb > 0)
	{
		first_nb = nb;
		last_nb = 1;
		while (first_nb > 10)
		{
			first_nb = first_nb / 10;
			last_nb = last_nb * 10;
		}
		c = first_nb + '0';
		write(1, &c, 1);
		nb = nb % last_nb;
	}
	write(1, "\n", 1);
}

/*int main ()
{
	ft_putnbr(45859676);
	ft_putnbr(1);
	return (0);
}*/
