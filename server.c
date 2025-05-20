/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:50:53 by aramos-m          #+#    #+#             */
/*   Updated: 2025/05/20 23:47:26 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define BUF_SIZE 100

struct s_msg{
	char	bin_to_char;
	int		count;
	char	*buf_sigusr;
	int		buf_count;
}t_msg;

char	*resize_buffer(void)
{
	char	*tmp_buf;
	int		i;

	i = 0;
	tmp_buf = malloc(t_msg.buf_count + BUF_SIZE);
	if (!tmp_buf)
		return (NULL);
	while (i != t_msg.buf_count)
	{
		tmp_buf[i] = t_msg.buf_sigusr[i];
		i++;
	}
	free(t_msg.buf_sigusr);
	return (tmp_buf);
}

/* SIGUSR1 =  10; SIGUSR2 = 12 */
void	handler_sigusr(int sig)
{
	if (sig == 10)
		t_msg.bin_to_char = t_msg.bin_to_char ^ (1 << t_msg.count);
	t_msg.count++;
	if (t_msg.count > 7)
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
		t_msg.count = 0;
		t_msg.bin_to_char = 0;
	}
}

int	main(void)
{
	pid_t				servidor;
	struct sigaction	act;

	servidor = getpid();
	t_msg.buf_sigusr = malloc(BUF_SIZE);
	if (!t_msg.buf_sigusr)
		return (0);
	printf("%d\n", servidor);
	act.sa_handler = handler_sigusr;
	sigaction(SIGUSR1, &act, NULL);
	act.sa_handler = handler_sigusr;
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		;
	return (0);
}
