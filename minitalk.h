/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:01:39 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/03/01 11:34:58 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(long int n);
int		ft_putstr(char *s);
int		power(int n, int p);
int		to_decimal(int *n);
void	sig_handler(int signum, siginfo_t *info, void *p);

#endif