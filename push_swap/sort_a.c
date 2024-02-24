/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:17:05 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/24 21:24:17 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_instructions_for_asc(t_lists *lists, t_node *node_b,
		t_vector *rotate_vector)
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
	t_node		*tmp;
	t_vector	*opt_vector;
	t_vector	*opt_vector_tmp;

	tmp = lists->list_b;
	opt_vector = NULL;
	while (tmp->next != lists->list_b)
	{
		init_vector(rotate_vector);
		count_instructions_for_asc(lists, tmp, rotate_vector);
		opt_vector_tmp = optimize_instructions(rotate_vector);
		if (opt_vector == NULL || opt_vector->instructions
			> opt_vector_tmp->instructions)
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
	opt_vector_tmp = optimize_instructions(rotate_vector);
	if (opt_vector == NULL || opt_vector->instructions
		> opt_vector_tmp->instructions)
	{
		free(opt_vector);
		opt_vector = opt_vector_tmp;
	}
	else
		free(opt_vector_tmp);
	return (opt_vector);
}

t_node	*handle_stack_a(t_lists *lists, int num_of_args)
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
		lists = push_a(lists);
		free(rotate_vector);
		free(opt_vector);
	}
	lists->list_a = put_smallest_at_the_top(lists);
	return (lists->list_a);
}
