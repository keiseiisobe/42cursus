/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:09:22 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/11 13:04:10 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*move(t_lists *lists, t_vector *vector)
{
	int	i;

	i = 0;
	while (i++ < vector->ra_count)
		rotate(lists, A);
	i = 0;
	while (i++ < vector->rb_count)
		rotate(lists, B);
	i = 0;
	while (i++ < vector->rr_count)
		rotate(lists, R);
	i = 0;
	while (i++ < vector->rra_count)
		reverse_rotate(lists, A);
	i = 0;
	while (i++ < vector->rrb_count)
		reverse_rotate(lists, B);
	i = 0;
	while (i++ < vector->rrr_count)
		reverse_rotate(lists, R);
	return (lists);
}

t_node	*put_smallest_at_the_top(t_lists *lists)
{
	int	flag;

	flag = get_cheapest_instructions_for_asc(lists->list_a);
	if (flag == RA)
		while (lists->list_a->value > lists->list_a->prev->value)
			rotate(lists, A);
	else
	{
		while (lists->list_a->value > lists->list_a->prev->value)
			reverse_rotate(lists, A);
	}
	return (lists->list_a);
}

t_node	*put_biggest_at_the_top(t_lists *lists)
{
	int	flag;

	flag = get_cheapest_instructions_for_desc(lists->list_b);
	if (flag == RB)
		while (lists->list_b->value < lists->list_b->prev->value)
			rotate(lists, B);
	else
	{
		while (lists->list_b->value < lists->list_b->prev->value)
			reverse_rotate(lists, B);
	}
	return (lists->list_b);
}
