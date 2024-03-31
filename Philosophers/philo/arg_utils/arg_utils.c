/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:08:11 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/20 16:19:20 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	args_are_not_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == FALSE)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_less_than(int num, int argc, char **argv)
{
	if (num == 1)
	{
		if (ft_atoi(argv[1]) == 0)
			return (true);
		if (argc == 6)
		{
			if (ft_atoi(argv[5]) == 0)
				return (true);
		}
	}
	else if (num == 60)
	{
		if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60
			|| ft_atoi(argv[4]) < 60)
			return (true);
	}
	return (false);
}

bool	is_more_than(long num, int argc, char **argv)
{
	if (num == 200)
	{
		if (ft_atoi(argv[1]) > 200)
			return (true);
	}
	else if (num == INT_MAX)
	{
		if (ft_atoi(argv[2]) == OVER_INT_MAX || ft_atoi(argv[3])
			== OVER_INT_MAX || ft_atoi(argv[4]) == OVER_INT_MAX)
			return (true);
		if (argc == 6)
		{
			if (ft_atoi(argv[5]) == OVER_INT_MAX)
				return (true);
		}
	}
	return (false);
}
