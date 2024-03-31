/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dupe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:35:04 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/14 14:41:37 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_dupe_for_single_arg(char **argv)
{
	char	**strs;
	int		i;
	int		j;
	int		flag;

	strs = ft_split(argv[1], ' ');
	check_error(strs == NULL);
	flag = 0;
	i = 0;
	while (strs[i + 1])
	{
		j = i + 1;
		while (strs[j])
		{
			if (ft_atoi(strs[i]) - ft_atoi(strs[j]) == SAME)
				flag = 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (flag == 0);
}

bool	is_dupe_for_multi_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i + 1])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) - ft_atoi(argv[j]) == SAME)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
