/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:28:37 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/08 11:16:21 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	int	bit;
	int	bit_count;

	error_check(argc != 3);
	error_check(ft_atoi(argv[1]) < 0);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		bit_count = 7;
		while (bit_count >= 0)
		{
			bit = (argv[2][i] >> bit_count) & 1;
			if (bit == 0)
				error_check(kill(pid, SIGUSR1) < 0);
			else
				error_check(kill(pid, SIGUSR2) < 0);
			usleep(60);
			bit_count--;
		}
		i++;
	}
}
