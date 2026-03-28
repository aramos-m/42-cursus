/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:34:57 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/29 20:46:50 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*#include <stdio.h>
#include <string.h>
int main ()
{
	char str[] = "Hello, World!";
	int orig;
	int cpy;
	
	orig = strlen(str);
	cpy = ft_strlen(str);

	printf("Original function: %i\n", orig);
	printf("Copied function: %i\n", cpy);

	return (0);
}*/
