/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:24:41 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/01/14 21:16:46 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
static int is_space(char c)
{
	if(c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
int ft_atoi(const char *str)
{
	int i;
	int res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while(is_space(str[i]))
		i++;
	if(str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if(str[i] == '+')
		i++;
	while(str[i] && str[i] >= '0' && str[i] <= '9')
	{
	res *= 10;
	res += str[i] - '0';
	i++;
	}
	return (res *sign);
}

void	sending(char c, int pid)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		kill(pid, ((c >> i) & 1) + SIGUSR1);
		usleep(300);
	}
}

void	ft_handler(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "success", 8);
}

int	main(int ac , char **av)
{
	int	pid;
	int	i;
	char *usage;
	int e;

	usage = "USAGE :./client";
	i = 0;

	if (ac != 3)
	{
		while(*usage)
			write(1, usage++,1);
		write(1, "\n", 1);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	e = kill(pid, 0);
	if (e == -1)
		write(1, "Bad pid \n", 14);
	signal(SIGUSR1, ft_handler);
	if	(pid < 1)
		exit(1);
	while (av[2][i])
		sending(av[2][i++], pid);
	sending('\0', pid);
	signal(SIGINT, ft_handler);
}
