/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:44:20 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/24 18:44:39 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

bool	is_int_max_for_single_arg(char **argv)
{
	int		i;
	char	**strs;
	int		flag;

	flag = 0;
	strs = ft_split(argv[1], ' ');
	i = 0;
	while (strs[i])
	{
		if (INT_MAX < ft_atoi(strs[i]) || INT_MIN > ft_atoi(strs[i]))
			flag = 1;
		i++;
	}
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	if (flag == 1)
		return (false);
	return (true);
}

bool	is_int_max_for_multi_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (INT_MAX < ft_atoi(argv[i]) || INT_MIN > ft_atoi(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
