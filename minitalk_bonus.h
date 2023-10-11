/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:48:13 by ykhalil-          #+#    #+#             */
/*   Updated: 2023/02/28 18:57:26 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdarg.h>
# include <unistd.h>

struct	s_data
{
	int	data_recieved;
	int	data_sent;
};

void	ft_putchar(char c);
void	ft_putnbr(long int n);
int		ft_putstr(char *s);
#endif