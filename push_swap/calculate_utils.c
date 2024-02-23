/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:05 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/23 14:32:09 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_vector(t_vector *vector)
{
	vector->instructions = 0;
	vector->ra_count = 0;
	vector->rb_count = 0;
	vector->rr_count = 0;
	vector->rra_count = 0;
	vector->rrb_count = 0;
	vector->rrr_count = 0;
}

int	check_dupe(int instruction_a, int instruction_b)
{
	if (instruction_a == 0 || instruction_b == 0)
		return (0);
	else
	{
		if (instruction_a < instruction_b)
			return (instruction_a);
		else
			return (instruction_b);
	}
}

int	get_min(int ra_rb_count, int ra_rrb_count, int rra_rb_count, int rra_rrb_count)
{
	int	min;

	min = ra_rb_count;
	if (min > ra_rrb_count)
		min = ra_rrb_count;
	if (min > rra_rb_count)
		min = rra_rb_count;
	if (min > rra_rrb_count)
		min = rra_rrb_count;
	return (min);
}

int	get_cheapest_instructions(t_node *list_a)
{
	int	ra_count;
	int	rra_count;
	t_node	*tmp;

	ra_count = 0;
	rra_count = 0;
	tmp = list_a;
	while (tmp->value > tmp->prev->value)
	{
		ra_count++;
		tmp = tmp->next;
	}
	tmp = list_a;
	while (tmp->value > tmp->prev->value)
	{
		rra_count++;
		tmp = tmp->prev;
	}
	if (ra_count <= rra_count)
		return (RA);
	else
		return (RRA);
}
