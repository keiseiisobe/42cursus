/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:29:02 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/13 12:44:10 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int flag)
{
	if (flag == SIGUSR1)
		g_flag = 0;
	else
		g_flag = 1;
}

void	set(struct sigaction *sa)
{
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR2);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sa->sa_flags = SA_RESTART;
	sa->sa_handler = signal_handler;
	error_check(sigaction(SIGUSR1, sa, NULL) < 0, SIGACTION);
	error_check(sigaction(SIGUSR2, sa, NULL) < 0, SIGACTION);
}

void	update_bits(t_info *bits_info)
{
	if (g_flag == 0)
	{
		if (bits_info->bits_count == 0)
			bits_info->bits = 0;
		else
			bits_info->bits = bits_info->bits << 1;
	}
	else
	{
		if (bits_info->bits_count == 0)
			bits_info->bits = 1;
		else
			bits_info->bits = (bits_info->bits << 1) + 1;
	}
}

int	main(void)
{
	struct sigaction	sa;
	t_info				bits_info;

	error_check(ft_printf("PID: %d\n", getpid()) < 0, WRITE);
	set(&sa);
	bits_info.bits_count = 0;
	while (1)
	{
		pause();
		update_bits(&bits_info);
		bits_info.bits_count++;
		if (bits_info.bits_count == 8)
		{
			error_check(write(1, &bits_info.bits, 1) < 0, WRITE);
			bits_info.bits_count = 0;
		}
	}
	return (0);
}
