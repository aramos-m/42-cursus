/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:38:59 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/03 19:05:39 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

#define BUF_SIZE 100

struct s_msg
{
	char	current_char;
	int		bit_count;
	char	*buf_sigusr;
	int		buf_count;
}t_msg;