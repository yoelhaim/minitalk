/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:24:41 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/02/11 09:44:28 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
	res *= 10;
	res += str[i] - '0';
	i++;
	}
	return (res * sign);
}

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

void	ft_handler(int sig, siginfo_t *list_info, void *no)
{
	(void) no;
	(void) list_info;
	(void) sig;
	write(STDOUT_FILENO, "successfully send", 18);
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	sa.sa_sigaction = &ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	if (ac != 3)
	{
		write (1, "Usage: ./client [server PID] [string to send]\n", 47);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid < 1)
	{
		write(1, "Bad pid \n", 10);
		exit(EXIT_FAILURE);
	}
	while (av[2][i])
		sending(av[2][i++], pid);
	sending('\0', pid);
}
