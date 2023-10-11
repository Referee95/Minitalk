/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:01:34 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/03/01 21:15:36 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int n, int p)
{
	int	r;
	int	i;

	r = 1;
	i = 0;
	while (i++ < p)
		r *= n;
	return (r);
}

int	to_decimal(int *n)
{
	int	r;
	int	j;
	int	i;

	j = 0;
	r = 0;
	i = 7;
	while (j < 8)
	{
		r = r + n[j] * power(2, i);
		j++;
		i--;
	}
	return (r);
}

void	sig_handler(int signum, siginfo_t *info, void *p)
{
	static int	n;
	int			array[8];
	int			dec;
	static int	pid;

	(void)p;
	if (pid != info->si_pid)
		n = 0;
	pid = info->si_pid;
	if (signum == SIGUSR2)
		array[n++] = 1;
	else
		array[n++] = 0;
	if (n == 8)
	{
		dec = to_decimal(array);
		ft_putchar(dec);
		n = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sig.sa_sigaction = &sig_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	while (1)
		pause();
	return (0);
}
