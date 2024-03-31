/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:28:37 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/16 16:59:33 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	arg_check(int argc, char *argv[])
{
	error_check(argc != 3, ARG);
	error_check(ft_isdigit_all(argv[1]) == false, PID);
	error_check(ft_atoi(argv[1]) < 100, PID);
	error_check(ft_atoi(argv[1]) > INT_MAX, PID);
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	int	bit;
	int	bit_count;

	arg_check(argc, argv);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		bit_count = 7;
		while (bit_count >= 0)
		{
			bit = (argv[2][i] >> bit_count) & 1;
			if (bit == 0)
				error_check(kill(pid, SIGUSR1) < 0, KILL);
			else
				error_check(kill(pid, SIGUSR2) < 0, KILL);
			usleep(700);
			bit_count--;
		}
		i++;
	}
	return (0);
}
