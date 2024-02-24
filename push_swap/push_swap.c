/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 08:59:30 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/24 21:31:20 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
__attribute__((destructor))
static void	destructor(void) {
	system("leaks -q push_swap");
}
*/
t_vector	*put_to_vector(t_vector *vector, int dupe, int flag)
{
	t_vector	*opt_vector;

	opt_vector = malloc(sizeof(t_vector));
	init_vector(opt_vector);
	opt_vector->value = vector->value;
	if (flag == RARB)
	{
		opt_vector->ra_count = vector->ra_count - dupe;
		opt_vector->rb_count = vector->rb_count - dupe;
		opt_vector->rr_count = dupe;
		opt_vector->instructions = opt_vector->ra_count
			+ opt_vector->rb_count + opt_vector->rr_count;
	}
	else if (flag == RARRB)
	{
		opt_vector->ra_count = vector->ra_count;
		opt_vector->rrb_count = vector->rrb_count;
		opt_vector->instructions = opt_vector->ra_count + opt_vector->rrb_count;
	}
	else if (flag == RRARB)
	{
		opt_vector->rra_count = vector->rra_count;
		opt_vector->rb_count = vector->rb_count;
		opt_vector->instructions = opt_vector->rra_count + opt_vector->rb_count;
	}
	else if (flag == RRARRB)
	{
		opt_vector->rra_count = vector->rra_count - dupe;
		opt_vector->rrb_count = vector->rrb_count - dupe;
		opt_vector->rrr_count = dupe;
		opt_vector->instructions = opt_vector->rra_count
			+ opt_vector->rrb_count + opt_vector->rrr_count;
	}
	return (opt_vector);
}

t_node	*sort(t_lists *lists, int num_of_args, int flag)
{
	if (flag == ASC_THREE)
		return (handle_3_nums(lists, ASC));
	else if (flag == DESC_THREE)
		return (handle_3_nums(lists, DESC));
	else if (flag == LESS_THAN_4)
		return (handle_less_than_4_nums(lists, num_of_args));
	else if (flag == LESS_THAN_6)
		return (handle_less_than_6_nums(lists, num_of_args));
	else if (flag == ASC)
		return (handle_stack_a(lists, num_of_args));
	else
		return (handle_stack_b(lists, num_of_args));
}

t_node	*push_swap(t_lists *lists, int num_of_args)
{
	lists->list_b = NULL;
	if (num_of_args < 4)
		return (sort(lists, num_of_args, LESS_THAN_4));
	if (num_of_args < 6)
		return (sort(lists, num_of_args, LESS_THAN_6));
	pb_3_nums(lists);
	sort(lists, num_of_args, DESC_THREE);
	sort(lists, num_of_args, DESC);
	sort(lists, num_of_args, ASC_THREE);
	sort(lists, num_of_args, ASC);
	put_smallest_at_the_top(lists);
/*
//---------printf for testing list_b-------------
	t_node	*tmp_b;
	tmp_b = lists->list_b;

	if (tmp_b)
	{
		while (tmp_b && (tmp_b->next != lists->list_b))
		{
			printf("list_b : value is %d, address is %p, prev is %p, next is %p\n", tmp_b->value, tmp_b, tmp_b->prev, tmp_b->next);
			tmp_b = tmp_b->next;
		}
		printf("list_b : value is %d, address is %p, prev is %p, next is %p\n\n\n", tmp_b->value, tmp_b, tmp_b->prev, tmp_b->next);
	}
*/
	free_list(lists->list_b);
	return (lists->list_a);
}

bool	is_sorted(t_node *list_a)
{
	t_node	*tmp;

	tmp = list_a;
	while (tmp->next != list_a)
	{
		if (tmp->value > tmp->next->value)
			break ;
		tmp = tmp->next;
	}
	if (tmp->next != list_a)
		return (false);
	return (true);
}
