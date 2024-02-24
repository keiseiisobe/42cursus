/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:36:04 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/24 21:26:50 by kisobe           ###   ########.fr       */
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

	i = 0;
	while (i++ < num_of_args - 3)
		push_b(lists);
	handle_3_nums(lists, ASC);
	i = 0;
	while (i++ < num_of_args - 3)
	{
		rotate_vector = malloc(sizeof(t_vector));
		opt_vector = get_cheapest(lists, rotate_vector, ASC);
		lists = move(lists, opt_vector);
		lists = push_a(lists);
		free(rotate_vector);
		free(opt_vector);
	}
	lists->list_a = put_smallest_at_the_top(lists);
	return (lists->list_a);
}
