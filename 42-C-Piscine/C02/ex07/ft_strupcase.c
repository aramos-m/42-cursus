/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:05:38 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/27 10:21:39 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= ('a' - 'A');
		}
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int main()
{
	char str[] = "hola";
	printf("%s\n", ft_strupcase(str));

	return 0;
}*/
