/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:50:53 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/01 21:22:30 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"

#define BUF_SIZE 100

struct s_msg{
	char	bin_to_char;
	int		bin_count;
	char	*buf_sigusr;
	int		buf_count;
}t_msg;

char	*resize_buffer(void)
{
	char	*new_buf;
	int		i;

	i = 0;
	new_buf = malloc(t_msg.buf_count + BUF_SIZE);
	if (!new_buf)
		return (NULL);
	while (i != t_msg.buf_count)
	{
		new_buf[i] = t_msg.buf_sigusr[i];
		i++;
	}
	free(t_msg.buf_sigusr);
	return (new_buf);
}

/* SIGUSR1 =  10; SIGUSR2 = 12 */
void	handler_sigusr(int sig)
{
	if (sig == 10)
		t_msg.bin_to_char = t_msg.bin_to_char ^ (1 << t_msg.bin_count);
	t_msg.bin_count++;
	if (t_msg.bin_count > 7)
	{
		t_msg.buf_sigusr[t_msg.buf_count] = t_msg.bin_to_char;
		t_msg.buf_count++;
		if (t_msg.bin_to_char == '\0')
		{
			write(1, t_msg.buf_sigusr, t_msg.buf_count);
			free(t_msg.buf_sigusr);
			t_msg.buf_sigusr = malloc(BUF_SIZE);
			t_msg.buf_count = 0;
		}
		else if (t_msg.buf_count % BUF_SIZE == 0)
			t_msg.buf_sigusr = resize_buffer();
		t_msg.bin_count = 0;
		t_msg.bin_to_char = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	t_msg.buf_sigusr = malloc(BUF_SIZE);
	if (!t_msg.buf_sigusr)
		return (1);
	act.sa_handler = handler_sigusr;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	write(1, "El servidor está activo. Su PID es: ", 37);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		;
	return (0);
}
