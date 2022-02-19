/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:24:41 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/02/19 17:20:11 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sending(char c, int pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		kill (pid, SIGUSR1 + bit);
		usleep (800);
		i--;
	}
}

void	ft_handler(int sig)
{
	(void) sig;
	write(1, "successfully send", 18);
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;

	signal(SIGUSR1, ft_handler);
	i = 0;
	if (ac != 3)
	{
		write (1, "Usage: ./client [server PID] [string to send]\n", 47);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 1)
	{
		write(1, "Bad pid \n", 10);
		exit(1);
	}
	while (av[2][i])
		sending(av[2][i++], pid);
	sending('\0', pid);
	return (0);
}
