/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:32:50 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/28 18:17:42 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
	{
		i++;
	}
	if (n == i)
	{
		return (0);
	}
	return (s1[i] - s2[i]);
}

/*#include <stdio.h>
#include <string.h>
int main()
{
	char str1[] = "}oLa";
	char str2[] = "hola";
	int n = 1;
	int cpy;
	int orig;
	
	cpy = ft_strncmp(str1, str2, n);
	orig = strncmp(str1, str2, n);
	printf("Original function: %d\n", orig);
	printf("Copied function: %d\n", cpy);

    return 0;
}*/
