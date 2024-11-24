/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:59:26 by aramos-m          #+#    #+#             */
/*   Updated: 2024/11/24 20:01:24 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	main(int argc, char **argv)
{
	int		fd[argc];
	char	*buffer;
	size_t	count;
	int		i;

	buffer = 1;
	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		fd[i] = open(argv[i], O_RDONLY);
		i++;
	}
	while (argc > 1)
	{
		if (i >= argc)
			i = 1;
		if (fd[i] >= 0)
		{
			buffer = get_next_line(fd[i]);
			printf("%s\n", buffer);
			if (!buffer)
			{
				argc--;
				fd[i] = -1;
			}
		}
		i++;
	}
	return (1);
}
