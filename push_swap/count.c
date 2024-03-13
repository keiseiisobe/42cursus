/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:20:16 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/11 12:57:37 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_instructions_for_asc(t_lists *lists, t_node *node_b,
		t_vector *rotate_vector)
{
	rotate_vector->value = node_b->value;
	count_ra_for_asc(lists, node_b, rotate_vector);
	count_rra_for_asc(lists, node_b, rotate_vector);
	count_rb_for_asc(lists, node_b, rotate_vector);
	count_rrb_for_asc(lists, node_b, rotate_vector);
}

void	count_instructions_for_desc(t_lists *lists, t_node *node_a,
		t_vector *rotate_vector)
{
	rotate_vector->value = node_a->value;
	count_rb_for_desc(lists, node_a, rotate_vector);
	count_rrb_for_desc(lists, node_a, rotate_vector);
	count_ra_for_desc(lists, node_a, rotate_vector);
	count_rra_for_desc(lists, node_a, rotate_vector);
}
