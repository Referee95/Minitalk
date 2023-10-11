/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:47:37 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/28 13:09:10 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

struct s_data	g_data;

int	ft_atoi(char *str)
{
	int	n;
	int	i;
	int	s;

	n = 0;
	i = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (n * s);
}

void	bit_bit(char c, int pid)
{
	int	l;

	l = 7;
	while (l >= 0)
	{
		if ((c >> l) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		l--;
		usleep(250);
	}
	g_data.data_sent++;
}

void	succes(int signum)
{
	if (signum == SIGUSR2)
	{
		g_data.data_recieved++;
		usleep(25);
	}
}

int	main(int ac, char **av)
{
	int					i;
	int					pid;
	struct sigaction	sa;

	i = 0;
	sa.sa_handler = succes;
	sigaction(SIGUSR2, &sa, NULL);
	g_data.data_recieved = 0;
	g_data.data_sent = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			bit_bit(av[2][i], pid);
			i++;
		}
		if (g_data.data_sent == g_data.data_recieved)
			write(1, "Success\n", 9);
		else
			write(1, "Fail\n", 6);
	}
}
