/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:50:53 by aramos-m          #+#    #+#             */
/*   Updated: 2025/05/14 21:58:39 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

struct s_msg{
    char bin_to_char;
    int count;
}t_msg;

void handler_sigusr1()
{
    t_msg.bin_to_char = t_msg.bin_to_char ^ (1 << t_msg.count);
    t_msg.count++;
    if (t_msg.count > 7)
    {
        write(1, &t_msg.bin_to_char, 1);
        t_msg.count = 0;
        t_msg.bin_to_char = 0;
    }
    //printf("------------- %u SIGUSR1\n", t_msg.bin_to_char);
}

void handler_sigusr2()
{
    t_msg.count++;
    if (t_msg.count > 7)
    {
        write(1, &t_msg.bin_to_char, 1);
        t_msg.count = 0;
        t_msg.bin_to_char = 0;
    }
    //printf("------------------ %u SIGUSR2\n", t_msg.bin_to_char);
}

int main(void)
{
    pid_t servidor;
    struct sigaction act;
    servidor = getpid();

    printf("%d\n", servidor);
    act.sa_handler = handler_sigusr1;
    sigaction(SIGUSR1, &act, NULL);
    act.sa_handler = handler_sigusr2;
    sigaction(SIGUSR2, &act, NULL);
    while (1)
    {

    }
    return (0);
}

// int signal(int pid, int sig)