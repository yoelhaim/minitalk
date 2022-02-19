/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:11:19 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/02/19 17:20:01 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_handler(int sig, siginfo_t *list_info, void *no)
{
	static char	c;
	static int	i;
	static int	last;

	(void) no;
	if (last != 0 && last != list_info->si_pid)
	{
		write(1, "\n", 1);
		i = 0;
		c = 0;
	}
	c = (c << 1) | (sig & 1);
	i++;
	if (i == 8)
	{
		if (c == 0)
			kill (list_info->si_pid, SIGUSR1);
		else
			write (1, &c, 1);
		i = 0;
		c = 0;
	}
	last = list_info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write (1, "pid => ", 8);
	ft_putnbr (getpid());
	write (1, "\n", 1);
	while (1)
		pause();
	return (0);
}
