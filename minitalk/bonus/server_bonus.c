/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:29:39 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/12 12:45:52 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(void)
{
	struct sigaction	sa;
	t_info				bit_info;

	error_check(ft_printf("PID: %d\n", getpid()) < 0, WRITE);
	set(&bit_info, &sa);
	while (1)
	{
		pause();
		if (bit_info.char_weight == 0)
			get_char_weight(&bit_info);
		bit_info.bits_count++;
		update_bits(&bit_info);
		ready_for_next_bits(&bit_info);
	}
	return (0);
}
/*
__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q server_bonus");
}
*/
