/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:59:26 by aramos-m          #+#    #+#             */
/*   Updated: 2024/11/24 15:56:12 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	main(void)
{
	int		fd;
	char	*buffer;
	size_t	count;

	buffer = 1;
	fd = open("./aramos-m.txt", O_RDONLY);
	buffer = get_next_line(55);
	printf("%s\n", buffer);
	printf("%d\n" , strcmp(buffer, "01234567890123456789012345678901234567890"));
	return 1;
	
	// buffer = get_next_line(-3);
	// printf("%s", buffer);
	// free (buffer);
}
