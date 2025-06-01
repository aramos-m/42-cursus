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

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;
	int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

void char_to_bin(pid_t pid, char* msg)
{
    int count;
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
    if (argc != 3)
        return (1);
    char_to_bin(ft_atoi(argv[1]), argv[2]);
    return (0);
}