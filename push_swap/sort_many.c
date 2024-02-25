/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:14:19 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/25 16:10:00 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*handle_stack_a(t_lists *lists, int num_of_args)
{
	t_vector	*rotate_vector;
	t_vector	*opt_vector;
	int			i;

	i = 0;
	while (i++ < num_of_args - 3)
	{
		rotate_vector = malloc(sizeof(t_vector));
		opt_vector = get_cheapest(lists, rotate_vector, ASC);
		lists = move(lists, opt_vector);
		push_a(lists);
		free(rotate_vector);
		free(opt_vector);
	}
	lists->list_a = put_smallest_at_the_top(lists);
	return (lists);
}

t_lists	*handle_stack_b(t_lists *lists, int num_of_args)
{
	t_vector	*rotate_vector;
	t_vector	*opt_vector;
	int			i;

	i = 0;
	while (i++ < num_of_args - 6)
	{
		rotate_vector = malloc(sizeof(t_vector));
		opt_vector = get_cheapest(lists, rotate_vector, DESC);
		lists = move(lists, opt_vector);
		push_b(lists);
		free(rotate_vector);
		free(opt_vector);
	}
	lists->list_b = put_biggest_at_the_top(lists);
	return (lists);
}
