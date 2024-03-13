/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:30:05 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/12 12:45:45 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	reset(t_info *bit_info)
{
	bit_info->bits = 0;
	bit_info->bits_count = 0;
	if (bit_info->char_index - 1 == bit_info->char_weight)
	{
		bit_info->char_weight = 0;
		bit_info->char_index = 0;
		free(bit_info->str);
	}
}

void	ready_for_next_bits(t_info *bit_info)
{
	if (bit_info->bits_count == 8)
	{
		bit_info->str[bit_info->char_index] = bit_info->bits;
		bit_info->char_index++;
		if (bit_info->char_index == bit_info->char_weight)
		{
			bit_info->str[bit_info->char_index++] = '\0';
			error_check(write(1, bit_info->str, ft_strlen(bit_info->str) + 1)
				< 0, WRITE);
		}
		reset(bit_info);
	}
}
