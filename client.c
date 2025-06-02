/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:53:10 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/01 21:22:17 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void char_to_bin(pid_t pid, char* msg)
{
    int count ;
    int i;

    i = 0;
    while(msg[i])
    {
        count = 0;
        while(count < 8)
        {
            if(msg[i] & (1 << count))
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            count++;
            usleep(500);
        }
        i++;
    }
    count = 0;
    while(count < 8)
    {
        kill(pid, SIGUSR2);
        count++;
        usleep(500);
    }
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc != 3)
    {
        write(1, "Error: número de argumentos no válido\n", 40);
        return (1);
    }
    while (argv[1][i])
    {
        if (!ft_isdigit(argv[1][i]))
        {
            write(1, "Error: PID no válido\n", 23);
            return (1);
        }
        i++;
    }
    char_to_bin(ft_atoi(argv[1]), argv[2]);
    return (0);
}