/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:36:04 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/23 17:54:27 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_3_nums(t_lists *lists)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		push_b(lists);
		i++;
	}
}

t_node	*handle_3_nums(t_lists *lists, int flag)
{
	if (flag == ASC)
	{
		if (lists->list_a->value > lists->list_a->next->value)
			lists->list_a = swap(lists->list_a, A);
		if (lists->list_a->next->value > lists->list_a->next->next->value)
			reverse_rotate(lists, A);
		if (lists->list_a->value > lists->list_a->next->value)
			lists->list_a = swap(lists->list_a, A);
		return (lists->list_a);
	}
	else
	{
		if (lists->list_b->value < lists->list_b->next->value)
			lists->list_b = swap(lists->list_b, B);
		if (lists->list_b->next->value < lists->list_b->next->next->value)
			reverse_rotate(lists, B);
		if (lists->list_b->value < lists->list_b->next->value)
			lists->list_b = swap(lists->list_b, B);
		return (lists->list_b);
	}
}

t_node	*handle_less_than_4_nums(t_lists *lists, int num_of_args)
{
	if (num_of_args == 2)
		return (swap(lists->list_a, A));
	else
		return (handle_3_nums(lists, ASC));
}

t_node	*handle_less_than_6_nums(t_lists *lists, int num_of_args)
{
	t_vector	*rotate_vector;
	t_vector	*opt_vector;
	int			i;

//-------count the nums of push_b----------
	i = 0;
	while (i++ < num_of_args - 3)
		push_b(lists);
//-------sort stack A in ascending order---------
	handle_3_nums(lists, ASC);
//------calculate which number in stack B is the cheapest------
	i = 0;
	while (i++ < num_of_args - 3)
	{
		rotate_vector = malloc(sizeof(t_vector));
		opt_vector = search_cheapest_one(lists, rotate_vector);
//---you have to handle the last one that is needed no optimization---
		printf("opt_value is %d, ra_count is %d, rb_count is %d, rr_count is %d, rra_count is %d, rrb_count is %d, rrr_count is %d\n", opt_vector->value, opt_vector->ra_count, opt_vector->rb_count, opt_vector->rr_count, opt_vector->rra_count, opt_vector->rrb_count, opt_vector->rrr_count);
		lists = move_the_one(lists, opt_vector);
		lists = push_a(lists);
		lists->list_a = put_smallest_at_the_top(lists);
		free(rotate_vector);
		free(opt_vector);
	}
	return (lists->list_a);
}
