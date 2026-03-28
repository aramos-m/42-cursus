/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:24:42 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/27 10:32:34 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
		{
			str[i] += ('a' - 'A');
		}
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int main()
{
	char str[] = "HOLA";
	printf ("%s\n", ft_strlowcase(str));
	
	return 0;
}*/
