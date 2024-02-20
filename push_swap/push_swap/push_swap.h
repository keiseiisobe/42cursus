/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:27 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/20 11:09:55 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

typedef struct s_arg {
	int		argc;
	char	**argv;
	int		num_of_args;
}	t_arg;

typedef struct s_node {
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_lists {
	t_node	*list_a;
	t_node	*list_b;
}	t_lists;

void	arg_init(t_arg *arg, int argc, char *argv[]);
t_arg	*arg_check(int argc, char *argv[]);
t_node	*init_list(t_arg *arg);
t_node	*create_first_node(t_node *node, t_node *list);
int		*convert_args_to_int_arr(t_arg *arg);
t_node	*sort_nums(t_lists *lists, int num_of_args);
t_lists	*push_b(t_lists *lists);
t_node	*swap_a(t_node *list);
void	check_error(bool error);
void	free_list(t_node *list);

# endif
