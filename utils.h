/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:06:27 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/02/20 15:40:13 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

struct s_utils
{
	int	i;
	int	pid;
}t_utils;

void	ft_putnbr(unsigned int nb);
int		ft_atoi(const char *str);

#endif
