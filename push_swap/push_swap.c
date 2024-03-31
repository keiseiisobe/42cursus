/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 08:59:30 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/20 13:14:45 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vector	*update_vector(t_vector *vector, int dupe, int flag)
{
	t_vector	*opt_vector;

	opt_vector = malloc(sizeof(t_vector));
	check_error(opt_vector == NULL);
	init_vector(opt_vector);
	opt_vector->value = vector->value;
	if (flag == RARB)
		update_rarb_vector(opt_vector, vector, dupe);
	else if (flag == RRARB)
		update_rrarb_vector(opt_vector, vector);
	else if (flag == RARRB)
		update_rarrb_vector(opt_vector, vector);
	else if (flag == RRARRB)
		update_rrarrb_vector(opt_vector, vector, dupe);
	return (opt_vector);
}

t_lists	*push_swap(t_arg *arg)
{
	t_lists	*lists;

	lists = malloc(sizeof(t_lists));
	check_error(lists == NULL);
	lists->list_a = init_list(arg);
	lists->list_b = NULL;
	if (is_sorted(lists->list_a) == true)
		exit(0);
	if (arg->num_of_args < 4)
		return (sort(lists, arg->num_of_args, LESS_THAN_4));
	if (arg->num_of_args < 6)
		return (sort(lists, arg->num_of_args, LESS_THAN_6));
	pb_3_times(lists);
	sort(lists, arg->num_of_args, DESC_THREE);
	sort(lists, arg->num_of_args, DESC);
	sort(lists, arg->num_of_args, ASC_THREE);
	sort(lists, arg->num_of_args, ASC);
	free_list(lists->list_b);
	return (lists);
}

/*
//---------printf for testing list_b-------------
	t_node	*tmp_b;
	tmp_b = lists->list_b;

	if (tmp_b)
	{
		while (tmp_b && (tmp_b->next != lists->list_b))
		{
			printf("list_b : value is %d, address is %p, prev is %p,
			next is %p\n", tmp_b->value, tmp_b, tmp_b->prev, tmp_b->next);
			tmp_b = tmp_b->next;
		}
		printf("list_b : value is %d, address is %p, prev is %p,
		next is %p\n\n\n", tmp_b->value, tmp_b, tmp_b->prev, tmp_b->next);
	}
*/
