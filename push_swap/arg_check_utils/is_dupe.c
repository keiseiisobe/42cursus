/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dupe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:35:04 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/25 14:46:14 by kisobe           ###   ########.fr       */
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
	flag = 0;
	i = 0;
	while (strs[i + 1])
	{
		j = i + 1;
		while (strs[j])
		{
			if (ft_strncmp(strs[i], strs[j++], ft_strlen(strs[i]) + 1) == 0)
				flag = 1;
		}
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
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i]) + 1) == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
