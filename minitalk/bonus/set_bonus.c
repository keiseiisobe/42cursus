/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:30:14 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/12 12:46:45 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int flag, siginfo_t *info, void *ptr)
{
	(void)ptr;
	if (flag == SIGUSR1)
		g_flag_server = 0;
	else
		g_flag_server = 1;
	usleep(50);
	error_check(kill(info->si_pid, SIGUSR1) < 0, KILL);
}

void	set(t_info *bit_info, struct sigaction *sa)
{
	bit_info->bits = 0;
	bit_info->bits_count = 0;
	bit_info->char_weight = 0;
	bit_info->char_index = 0;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR2);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sa->sa_flags = SA_SIGINFO | SA_RESTART;
	sa->sa_sigaction = signal_handler;
	error_check(sigaction(SIGUSR1, sa, NULL) < 0, SIGACTION);
	error_check(sigaction(SIGUSR2, sa, NULL) < 0, SIGACTION);
}
