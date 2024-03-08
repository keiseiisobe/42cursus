/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:29:11 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/08 13:01:13 by kisobe           ###   ########.fr       */
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
				error_check(kill(pid, SIGUSR1) < 0);
			else
				error_check(kill(pid, SIGUSR2) < 0);
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

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	(void)argc;
	error_check(argc != 3);
	error_check(ft_atoi(argv[1]) < 0);
	pid = ft_atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = signal_handler_client;
	sigaction(SIGUSR1, &sa, NULL);
	send_bits(pid, argv[2]);
	return (0);
}
/*
__attribute__((destructor))
static void destructor() {
    system("leaks -q client_bonus");
}
*/
