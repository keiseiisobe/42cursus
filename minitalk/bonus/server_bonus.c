/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:29:39 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/08 13:04:12 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(void)
{
	struct sigaction	*sa1;
	struct sigaction	*sa2;
	t_info				*bit_info;

	error_check(ft_printf("PID: %d\n", getpid()) < 0, WRITE);
	bit_info = malloc(sizeof(t_info));
	sa1 = malloc(sizeof(struct sigaction));
	sa2 = malloc(sizeof(struct sigaction));
	error_check(bit_info == NULL || sa1 == NULL || sa2 == NULL, MALLOC);
	set(bit_info, sa1, sa2);
	while (1)
	{
		pause();
		usleep(80);
		if (bit_info->char_weight == 0)
			get_char_weight(bit_info, g_flag_server);
		bit_info->bits_count++;
		update_bits(bit_info);
		ready_for_next_bits(bit_info);
	}
	free_all(sa1, sa2, bit_info);
}
/*
__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q server_bonus");
}
*/
