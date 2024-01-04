/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:30:52 by aramos-m          #+#    #+#             */
/*   Updated: 2024/01/04 01:30:55 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_line_break(char *backup)
{
    int i;

    i = 0;
	if (!backup)
		return (0);
    while(backup[i])
    {
        if(backup[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*scat;
	int		i;
	int		j;
	int		lens1;
	int		lens2;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	scat = malloc(lens1 + lens2 + 1);
	if (!scat)
		return (NULL);
	while (s1[i])
		scat[j++] = s1[i++];
	i = 0;
	while (s2[i])
		scat[j++] = s2[i++];
	scat[j] = '\0';
	return (scat);
}