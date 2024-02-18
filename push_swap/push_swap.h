/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:27 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/13 09:23:37 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "stdio.h"

typedef struct s_node {
	int	value;
  int index;
	void*	prev;
	void*	next;
} t_node;

typedef struct s_arg {
	int	argc;
	int	*argv[];
	int	arg_num;
} t_arg;

void  arg_init(t_arg *arg, int argc, char *argv[]);
t_arg *arg_check(int argc, char *argv[]);
int▸*init_list(t_arg *arg);
int▸*convert_args_to_int_arr(t_arg *arg);

# endif
