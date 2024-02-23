/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:27 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/23 15:23:22 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

# define A 0
# define B 1
# define R 2

# define ASC 0
# define DESC 1

# define COUNT_ONE_PUSH 1

# define RA 0
# define RRA 1
# define RB 2
# define RRB 3
# define RARB 4
# define RARRB 5
# define RRARB 6
# define RRARRB 7


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

typedef struct s_vector {
	int	value;
	int	instructions;
	int	ra_count;
	int	rb_count;
	int	rr_count;
	int	rra_count;
	int	rrb_count;
	int	rrr_count;
}	t_vector;

void		arg_init(t_arg *arg, int argc, char *argv[]);
t_arg		*arg_check(int argc, char *argv[]);
t_node		*init_list(t_arg *arg);
t_node		*create_first_node(t_node *node, t_node *list);
int			*convert_args_to_int_arr(t_arg *arg);
t_node		*sort_nums(t_lists *lists, int num_of_args);
t_node		*handle_3_nums(t_lists *lists, int flag);
void		pb_3_nums(t_lists *lists);
t_node		*handle_less_than_4_nums(t_lists *lists, int num_of_args);
t_node		*handle_less_than_6_nums(t_lists *lists, int num_of_args);
t_lists		*push_a(t_lists *lists);
t_lists		*push_b(t_lists *lists);
t_node		*swap(t_node *list, int flag);
void		rotate(t_lists *lists, int flag);
void		reverse_rotate(t_lists *lists, int flag);
t_vector	*put_to_vector(t_vector *vector, int dupe, int flag);
void		init_vector(t_vector *vector);
int			check_dupe(int instruction_a, int instruction_b);
int			get_min(int ra_rb_count, int ra_rrb_count, int rra_rb_count, int rra_rrb_count);
t_vector	*optimize_instructions(t_vector *vector);
void		count_instructions(t_lists *lists, t_node *node_b, t_vector *rotate_vector);
t_vector	*search_cheapest_one(t_lists *lists, t_vector *rotate_vector);
int			get_cheapest_instructions(t_node *list_a);
t_lists		*move_the_one(t_lists *lists, t_vector *vector);
t_node		*put_smallest_at_the_top(t_lists *lists);
void		check_error(bool error);
void		free_list(t_node *list);

# endif
