/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:29:11 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/16 17:07:23 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bits(int pid, char *str)
{
	int	bit_shift;
	int	bit;
	int	i;

	i = 0;
	while (str[i])
	{
		bit_shift = 7;
		while (bit_shift >= 0)
		{
			bit = (str[i] >> bit_shift) & 1;
			if (bit == 0)
				error_check(kill(pid, SIGUSR1) < 0, KILL);
			else
				error_check(kill(pid, SIGUSR2) < 0, KILL);
			pause();
			usleep(500);
			bit_shift--;
		}
		i++;
	}
}

void	signal_handler_client(int flag)
{
	(void)flag;
	return ;
}

void	arg_check(int argc, char *argv[])
{
	error_check(argc != 3, ARG);
	error_check(ft_isdigit_all(argv[1]) == false, PID);
	error_check(ft_atoi(argv[1]) < 100, PID);
	error_check(ft_atoi(argv[1]) > INT_MAX, PID);
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	arg_check(argc, argv);
	pid = ft_atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = signal_handler_client;
	error_check(sigaction(SIGUSR1, &sa, NULL), SIGACTION);
	send_bits(pid, argv[2]);
	return (0);
}
/*
__attribute__((destructor))
static void destructor() {
    system("leaks -q client_bonus");
}
*/
