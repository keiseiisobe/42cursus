/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:29:55 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/12 12:44:45 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	get_char_weight(t_info *bit_info)
{
	static int	count = 0;

	if (g_flag_server == 0)
	{
		if (count == 0)
			count++;
		bit_info->str = malloc((count + 1) * sizeof(char));
		error_check(bit_info->str == NULL, MALLOC);
		bit_info->char_weight = count;
		count = 0;
	}
	else
		count++;
}

void	update_bits(t_info *bit_info)
{
	if (g_flag_server == 0)
	{
		if (bit_info->bits_count == 1)
			bit_info->bits = 0;
		else
			bit_info->bits = bit_info->bits << 1;
	}
	else
	{
		if (bit_info->bits_count == 1)
			bit_info->bits = 1;
		else
			bit_info->bits = (bit_info->bits << 1) + 1;
	}
}
