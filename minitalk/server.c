/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:29:02 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/08 11:18:04 by kisobe           ###   ########.fr       */
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

void	set(struct sigaction *sa1, struct sigaction *sa2)
{
	sigemptyset(&sa1->sa_mask);
	sigemptyset(&sa2->sa_mask);
	sigaddset(&sa1->sa_mask, SIGUSR2);
	sigaddset(&sa2->sa_mask, SIGUSR1);
	sa1->sa_flags = SA_RESTART;
	sa2->sa_flags = SA_RESTART;
	sa1->sa_handler = signal_handler;
	sa2->sa_handler = signal_handler;
	error_check(sigaction(SIGUSR1, sa1, NULL) < 0, SIGACTION);
	error_check(sigaction(SIGUSR2, sa2, NULL) < 0, SIGACTION);
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
	struct sigaction	*sa1;
	struct sigaction	*sa2;
	t_info				*bits_info;

	error_check(ft_printf("PID: %d\n", getpid()) < 0, WRITE);
	bits_info = malloc(sizeof(t_info));
	sa1 = malloc(sizeof(struct sigaction));
	sa2 = malloc(sizeof(struct sigaction));
	error_check(sa1 == NULL || sa2 == NULL, MALLOC);
	set(sa1, sa2);
	bits_info->bits_count = 0;
	while (1)
	{
		pause();
		update_bits(bits_info);
		bits_info->bits_count++;
		if (bits_info->bits_count == 8)
		{
			error_check(write(1, &bits_info->bits, 1) < 0, WRITE);
			bits_info->bits_count = 0;
		}
	}
	free(bits_info);
	free(sa1);
	free(sa2);
}
