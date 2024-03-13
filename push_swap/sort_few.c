/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:36:04 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/11 13:06:23 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*handle_3_nums(t_lists *lists, int flag)
{
	if (flag == ASC)
	{
		if (lists->list_a->value > lists->list_a->next->value)
			lists->list_a = swap(lists->list_a, A);
		if (lists->list_a->next->value > lists->list_a->next->next->value)
			reverse_rotate(lists, A);
		if (lists->list_a->value > lists->list_a->next->value)
			lists->list_a = swap(lists->list_a, A);
		return (lists);
	}
	else
	{
		if (lists->list_b->value < lists->list_b->next->value)
			lists->list_b = swap(lists->list_b, B);
		if (lists->list_b->next->value < lists->list_b->next->next->value)
			reverse_rotate(lists, B);
		if (lists->list_b->value < lists->list_b->next->value)
			lists->list_b = swap(lists->list_b, B);
		return (lists);
	}
}

t_lists	*handle_less_than_4_nums(t_lists *lists, int num_of_args)
{
	if (num_of_args == 2)
	{
		lists->list_a = swap(lists->list_a, A);
		return (lists);
	}
	else
		return (handle_3_nums(lists, ASC));
}

t_lists	*handle_less_than_6_nums(t_lists *lists, int num_of_args)
{
	t_vector	*rotate_vector;
	t_vector	*opt_vector;
	int			i;

	i = 0;
	while (i++ < num_of_args - 3)
		push_b(lists);
	handle_3_nums(lists, ASC);
	i = 0;
	while (i++ < num_of_args - 3)
	{
		rotate_vector = malloc(sizeof(t_vector));
		check_error(rotate_vector == NULL);
		opt_vector = get_cheapest(lists, rotate_vector, ASC);
		lists = move(lists, opt_vector);
		push_a(lists);
		free(rotate_vector);
		free(opt_vector);
	}
	lists->list_a = put_smallest_at_the_top(lists);
	return (lists);
}
