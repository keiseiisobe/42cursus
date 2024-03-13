/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:22:13 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/11 12:57:56 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_ra_for_asc(t_lists *lists, t_node *node_b,
		t_vector *rotate_vector)
{
	t_node	*tmp;

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
}

void	count_ra_for_desc(t_lists *lists, t_node *node_a,
		t_vector *rotate_vector)
{
	t_node	*tmp;

	tmp = lists->list_a;
	while (node_a->value != tmp->value)
	{
		rotate_vector->ra_count++;
		tmp = tmp->next;
	}
}
