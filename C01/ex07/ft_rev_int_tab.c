/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:25:15 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/24 10:55:53 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		aux = tab[i];
		tab [i] = tab [j];
		tab [j] = aux;
		i++;
		j--;
	}
}

/*int main ()
{
	int arr [5] = {1, 2, 3, 4, 5};
	int size = 5;
	int i = 0;

	while (i < size)
	{
		printf("%i",arr[i]);
		i++;
	}
	
	ft_rev_int_tab(arr, size);
	printf("\n");
	
	i = 0;
	while (i < size)
	{
		printf("%i", arr[i]);
		i++;
	}
}*/
