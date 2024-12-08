/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:20:52 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/28 17:59:59 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0') && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*#include <string.h>
#include <stdio.h>
int main()
{
	char str1[] = "HolA";
	char str2[] = "Hola";
	int org;
	int cpy;	
	
	org = strcmp(str1, str2);
    cpy = ft_strcmp(str1, str2);
    printf("Original function: %d\n", org);
	printf("Copied function: %d\n", cpy);

    return 0;
}*/
