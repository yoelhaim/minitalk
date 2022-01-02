/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:11:19 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/01/02 21:39:44 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void    ft_handler(int sig, siginfo_t *list_info, void *no)
{
	static char	c;
	static int	cnt;
	static int	last_pid;

	(void)no;
	if (last_pid && last_pid != list_info->si_pid)
	{
		write(1, "\n", 1);
		c = 0;
		cnt = 0;
	}
	c = (c << 1) | (sig & 1);
	if (++cnt == 8)
	{
		write(1, &c, 1);
		c = 0;
		cnt = 0;
	}
	last_pid = list_info->si_pid;
}
int main()
{
	struct sigaction sa;

	sa.sa_sigaction = &ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("id is => %d\n", getpid());
	
	 while(1)
		pause();
}
