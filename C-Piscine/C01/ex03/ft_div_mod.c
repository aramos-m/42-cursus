/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:38:47 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/19 22:41:21 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	nb1;
	int	nb2;
	int	div;
	int	mod;

	nb1 = 42;
	nb2 = 10;
	ft_div_mod(nb1, nb2, &div, &mod);
	printf("El cociente es %i\n", div);
	printf("El resto es %i\n", mod);
}*/
