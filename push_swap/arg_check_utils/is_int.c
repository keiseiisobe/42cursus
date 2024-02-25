/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:33:19 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/25 14:46:40 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_int_for_single_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '-' || argv[1][i] == '+')
			return (ft_isdigit(argv[1][i + 1]));
		if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	is_int_for_multi_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				return (ft_isdigit(argv[i][j + 1]));
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
