/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:53:10 by aramos-m          #+#    #+#             */
/*   Updated: 2025/05/14 21:54:52 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h> // atoi

void char_to_bin(pid_t pid, char* msg)
{
    int count;
    int i;

    i = 0;
    while(msg[i])
    {
        printf("%c\n", msg[i]);
        count = 0;
        while(count < 8)
        {
            printf("%i\n", count);
            if(msg[i] & (1 << count))
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            count++;
            usleep(1000);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    char_to_bin(atoi(argv[1]), argv[2]);
    return (0);
}