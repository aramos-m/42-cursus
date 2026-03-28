/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:30:51 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/19 21:36:59 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*int	main(void)
{
	int	nb1;
	int	nb2;

	nb1 = 0;
	nb2 = 42;
	ft_swap(&nb1, &nb2);
	printf("El valor de nb1 era 0 ahora es %d\n", nb1);
	printf("El valor de nb2 era 42 ahora es %d\n", nb2);
}*/
