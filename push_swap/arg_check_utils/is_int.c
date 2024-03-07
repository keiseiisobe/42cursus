/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:33:19 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/25 19:22:12 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	is_valid_for_single_arg(char **argv, int *i)
{
	while (ft_isdigit(argv[1][*i]))
		(*i)++;
	if (argv[1][*i] != '\0' && argv[1][*i] != ' ')
		return (false);
	return (true);
}

static bool	is_valid_for_multi_arg(char **argv, int *i, int *j)
{
	if ((argv[*i][*j] == '-' || argv[*i][*j] == '+') &&
			ft_isdigit(argv[*i][*j + 1]))
	{
		(*j)++;
		while (ft_isdigit(argv[*i][*j]))
			(*j)++;
		if (argv[*i][*j] != '\0')
			return (false);
	}
	else if (ft_isdigit(argv[*i][*j]))
	{
		while (ft_isdigit(argv[*i][*j]))
			(*j)++;
		if (argv[*i][*j] != '\0')
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	is_int_for_single_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if ((argv[1][i] == '-' || argv[1][i] == '+') &&
				ft_isdigit(argv[1][i + 1]))
		{
			i++;
			if (is_valid_for_single_arg(argv, &i) == false)
				return (false);
		}
		else if (ft_isdigit(argv[1][i]))
		{
			if (is_valid_for_single_arg(argv, &i) == false)
				return (false);
		}
		else
			return (false);
		if (argv[1][i] == '\0')
			return (true);
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
			if (is_valid_for_multi_arg(argv, &i, &j) == false)
				return (false);
			if (argv[i][j] == '\0')
				break ;
			j++;
		}
		i++;
	}
	return (true);
}
