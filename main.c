/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:59:26 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/29 22:26:56 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd, fd2;
	char	*buffer;
	size_t	count;

	fd = open("./aramos-m.txt", O_RDONLY);
	fd2 = open("./test.txt", O_RDONLY);
	
	while (1)
	{
		buffer = get_next_line(fd);
		printf("%s", buffer);
		if (!buffer)
			break;
		buffer = get_next_line(fd2);
		printf("%s", buffer);
		if (!buffer)
			break;
	}
	return 1;
	
	// buffer = get_next_line(-3);
	// printf("%s", buffer);
	// free (buffer);
}
