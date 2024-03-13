/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:36:05 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/11 12:52:21 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	check_double_quote(char **argv)
{
	int		i;
	int		j;
	char	**strs;
	int		flag;

	flag = 0;
	i = 1;
	while (argv[i])
	{
		strs = ft_split(argv[i], ' ');
		check_error(strs == NULL);
		if (strs[1] != '\0')
			flag = 1;
		j = 0;
		while (strs[j])
			free(strs[j++]);
		free(strs);
		i++;
	}
	if (flag == 1)
		return (false);
	return (true);
}
