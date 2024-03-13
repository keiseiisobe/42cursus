/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:33:50 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/11 12:54:20 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_int_max_for_single_arg(char **argv)
{
	int		i;
	char	**strs;
	int		flag;

	flag = 0;
	strs = ft_split(argv[1], ' ');
	check_error(strs == NULL);
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
