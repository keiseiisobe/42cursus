/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:09:57 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/11 12:53:07 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_empty(char **argv)
{
	int	i;

	if (argv[1] == NULL)
		return (false);
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] != ' ')
			return (true);
		i++;
	}
	return (false);
}
