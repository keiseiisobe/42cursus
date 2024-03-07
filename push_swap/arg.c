/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:41:35 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/08 08:13:24 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_num_of_args(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

void	arg_init(t_arg *arg, int argc, char **argv)
{
	arg->argc = argc;
	arg->argv = argv;
}

t_arg	*handle_arg(int argc, char **argv)
{
	t_arg	*arg;

	if (argc < 2)
		exit(0);
	else if (argc == 2)
	{
		check_error(is_empty(argv) == false);
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
