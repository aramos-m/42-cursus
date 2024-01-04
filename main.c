/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:41:34 by aramos-m          #+#    #+#             */
/*   Updated: 2024/01/04 01:42:48 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main ()
{
    int fd;
    char *gnl;

    fd = open("aramos-m.txt",O_RDONLY);
    gnl = get_next_line(fd);

    printf("%s\n", gnl);

    return 0;
}
