/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:17:05 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/24 14:00:57 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_instructions_for_asc(t_lists *lists, t_node *node_b, t_vector *rotate_vector)
{
	t_node	*tmp;
	rotate_vector->value = node_b->value;
//--------count ra---------
	tmp = lists->list_a;
	while (1)
	{
		if (tmp->prev->value > tmp->value)
		{
			if (tmp->prev->value < node_b->value || tmp->value > node_b->value)
				break ;
			else
				rotate_vector->ra_count++;
		}
		else
		{
			if (tmp->prev->value < node_b->value && node_b->value < tmp->value)
				break ;
			else
				rotate_vector->ra_count++;
		}
		tmp = tmp->next;
	}
//--------count rra----------
	tmp = lists->list_a;
	while (1)
	{
		if (tmp->prev->value > tmp->value)
		{
			if (tmp->prev->value < node_b->value || tmp->value > node_b->value)
				break ;
			else
				rotate_vector->rra_count++;
		}
		else
		{
			if (tmp->prev->value < node_b->value && node_b->value < tmp->value)
				break ;
			else
				rotate_vector->rra_count++;
		}
		tmp = tmp->prev;
	}
//------count rb---------
	tmp = lists->list_b;
	while (node_b->value != tmp->value)
	{
		rotate_vector->rb_count++;
		tmp = tmp->next;
	}
//------count rrb--------
	tmp = lists->list_b;
	while (node_b->value != tmp->value)
	{
		rotate_vector->rrb_count++;
		tmp = tmp->prev;
	}
}

t_vector	*get_cheapest_for_asc(t_lists *lists, t_vector *rotate_vector)
{
	t_node	*tmp;
	t_vector	*opt_vector;
	t_vector	*opt_vector_tmp;

	tmp = lists->list_b;
	opt_vector = NULL;
	while (tmp->next != lists->list_b)
	{
		init_vector(rotate_vector);
//---------count instructions, and put them to vector (ra_count, rra_count, rb_count, rrb_count)--------
		count_instructions_for_asc(lists, tmp, rotate_vector);
//		printf("value is %d, ra_count is %d, rb_count is %d, rra_count is %d, rrb_count is %d\n", rotate_vector->value, rotate_vector->ra_count, rotate_vector->rb_count, rotate_vector->rra_count, rotate_vector->rrb_count);
//--------optimize combination of instructions (ra_rb_count, ra_rrb_count, rb_rra_count, rra_rrb_count)--------
		opt_vector_tmp = optimize_instructions(rotate_vector);
//--------if current best solution is better than previous one, then update !!!----------
		if (opt_vector == NULL || opt_vector->instructions > opt_vector_tmp->instructions)
		{
			free(opt_vector);
			opt_vector = opt_vector_tmp;
		}
		else
			free(opt_vector_tmp);
		tmp = tmp->next;
	}
	init_vector(rotate_vector);
	count_instructions_for_asc(lists, tmp, rotate_vector);
//	printf("value is %d, ra_count is %d, rb_count is %d, rra_count is %d, rrb_count is %d\n", rotate_vector->value, rotate_vector->ra_count, rotate_vector->rb_count, rotate_vector->rra_count, rotate_vector->rrb_count);
	opt_vector_tmp = optimize_instructions(rotate_vector);
	if (opt_vector == NULL || opt_vector->instructions > opt_vector_tmp->instructions)
	{
		free(opt_vector);
		opt_vector = opt_vector_tmp;
	}
	else
		free(opt_vector_tmp);
	return (opt_vector);
}
