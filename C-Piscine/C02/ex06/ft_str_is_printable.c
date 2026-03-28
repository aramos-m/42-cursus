/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:47:09 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/27 10:04:18 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] < 32) || (str[i] == 127)))
			i++;
		else
			return (0);
	}
	return (1);
}

/*#include <stdio.h>
int main()
{
	char str[] = "";
	int i;

	i = ft_str_is_printable(str);
	printf("%i", i);

	return 0;
}*/
