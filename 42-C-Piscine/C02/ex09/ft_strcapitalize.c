/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:34:01 by aramos-m          #+#    #+#             */
/*   Updated: 2023/08/27 10:59:48 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
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

char	*ft_strcapitalize(char *str)
{
	char	c;
	int		i;

	c = ' ';
	i = 0;
	ft_strupcase(str);
	while (str[i] != '\0')
	{
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
				|| (c >= '0' && c <= '9')) || i == 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= ('a' - 'A');
			}
		}
		c = str[i];
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int main()
{
	char c[] = "salut, comMent tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf ("%s\n", ft_strcapitalize(c));

	return 0;
}*/
