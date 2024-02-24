/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:41:35 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/24 21:07:20 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_init(t_arg *arg, int argc, char **argv)
{
	arg->argc = argc;
	arg->argv = argv;
}

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

t_arg	*arg_check(int argc, char **argv)
{
	t_arg	*arg;

	if (argc < 2)
		exit(0);
	else if (argc == 2)
	{
		check_error(is_int_for_single_arg(argv) == false);
		check_error(is_int_max_for_single_arg(argv) == false);
		check_error(is_dupe_for_single_arg(argv) == false);
	}
	else
	{
		check_error(is_int_for_multi_args(argv) == false);
		check_error(is_int_max_for_multi_args(argv) == false);
		check_error(is_dupe_for_multi_args(argv) == false);
		check_error(check_double_quote(argv) == false);
	}
	arg = malloc(sizeof(t_arg));
	arg_init(arg, argc, argv);
	return (arg);
}
