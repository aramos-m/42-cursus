/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:50:06 by aramos-m          #+#    #+#             */
/*   Updated: 2024/12/15 19:51:21 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd[2];
	char	*line1, *line2;


	fd[0] = open("dorian_gray.txt", O_RDONLY);
	fd[1] = open("wuthering_heights.txt", O_RDONLY);

	line1  = 1;
	while (line1 || line2)
	{
		line1 = get_next_line(fd[0]);
		if (line1)
		{
			printf("FD1: %s", line1);
			free(line1);
		}
		line2 = get_next_line(fd[1]);
		if (line2)
		{
			printf("FD2: %s", line2);
			free(line2);
		}
	}
}