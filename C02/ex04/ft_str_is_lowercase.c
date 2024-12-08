/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:18:05 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/26 22:31:02 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && *str <= 'z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int main ()
{
	char str[] = "";
	int i;
	
	i = ft_str_is_lowercase(str);
	printf("%i", i);
	
	return 0;
}*/
