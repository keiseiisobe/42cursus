#include "minitalk_bonus.h"

void	get_char_weight(t_info *bit_info, int bit_flag)
{
	static int	count = 0;

	if (bit_flag == 0)
	{
		if (count == 0)
			count++;
		bit_info->str = malloc((count + 1) * sizeof(char));
		error_check(bit_info->str == NULL);
		bit_info->char_weight = count;
		count = 0;
	}
	else
		count++;
}

void	update_bits(t_info *bit_info)
{
	if (sig_flag == 0)
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
