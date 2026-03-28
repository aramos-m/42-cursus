/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:50:09 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/23 17:49:32 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	order(int i, int size, int *tab, int aux1)
{
	int	aux2;
	int	j;
	int	k;

	while (i <= size -1)
	{
		j = i;
		while (j <= size - 1)
		{
			if (aux1 >= tab [j])
			{
				aux1 = tab [j];
				k = j;
			}
			j++;
		}
		aux2 = tab [i];
		tab [i] = aux1;
		tab [k] = aux2;
		i++;
		aux1 = tab [i];
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	aux1;
	int	i;

	i = 0;
	aux1 = *tab;
	order(i, size, tab, aux1);
}

/*int	main(void)
{
	int	v[4] = {5, 4, 3, 2};
	int	size = 4;
	int	i = 0;

	ft_sort_int_tab(v, size);
	while (i <= size -1)
	{
		printf("%i", v[i]);
		i++;
	}
	return (0);
}*/
