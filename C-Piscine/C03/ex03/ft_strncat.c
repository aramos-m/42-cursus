/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:58:58 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/28 18:52:15 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	int				j;
	unsigned int	k;	

	i = 0;
	j = 0;
	k = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && k < nb)
	{
		dest[i] = src[j];
		j++;
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>
int main()
{
	char str1[20] = "¡Hola,";
	char str2[] = "mundo!";
	unsigned int k = 1;

    printf("%s\n",ft_strncat(str1, str2, k));

    return 0;
}*/
