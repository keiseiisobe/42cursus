/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:24:33 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/11 12:58:10 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_rb_for_asc(t_lists *lists, t_node *node_b,
		t_vector *rotate_vector)
{
	t_node	*tmp;

	tmp = lists->list_b;
	while (node_b->value != tmp->value)
	{
		rotate_vector->rb_count++;
		tmp = tmp->next;
	}
}

void	count_rb_for_desc(t_lists *lists, t_node *node_a,
		t_vector *rotate_vector)
{
	t_node	*tmp;

	tmp = lists->list_b;
	while (1)
	{
		if (tmp->prev->value < tmp->value)
		{
			if (tmp->prev->value > node_a->value || tmp->value < node_a->value)
				break ;
			else
				rotate_vector->rb_count++;
		}
		else
		{
			if (tmp->prev->value > node_a->value && node_a->value > tmp->value)
				break ;
			else
				rotate_vector->rb_count++;
		}
		tmp = tmp->next;
	}
}
