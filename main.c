/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:59:26 by aramos-m          #+#    #+#             */
/*   Updated: 2024/11/19 20:32:16 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*buffer;
	size_t	count;

	fd = open("./aramos-m.txt", O_RDONLY);
	
		buffer = get_next_line(fd);
		printf("%s", buffer);
		buffer = get_next_line(fd);
		printf("%s", buffer);

	return 1;
	
	// buffer = get_next_line(-3);
	// printf("%s", buffer);
	// free (buffer);
}
