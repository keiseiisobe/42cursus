/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:50:51 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/24 13:59:51 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vector	*get_cheapest(t_lists *lists, t_vector *rotate_vector, int flag)
{
	if (flag == ASC)
		return (get_cheapest_for_asc(lists, rotate_vector));
	else
		return (get_cheapest_for_desc(lists, rotate_vector));
}

t_vector	*optimize_instructions(t_vector *vector)
{
	int	ra_rb_count;
	int	ra_rrb_count;
	int	rra_rb_count;
	int	rra_rrb_count;
	int	dupe_r;
	int	dupe_rr;
	int	min;

	dupe_r = check_dupe(vector->ra_count, vector->rb_count);
	ra_rb_count = vector->ra_count + vector->rb_count - dupe_r;
	ra_rrb_count = vector->ra_count + vector->rrb_count;
	rra_rb_count = vector->rra_count + vector->rb_count;
	dupe_rr = check_dupe(vector->rra_count, vector->rrb_count);
	rra_rrb_count = vector->rra_count + vector->rrb_count - dupe_r;
//--------compare them and get the best solution in current node--------
	min = get_min(ra_rb_count, ra_rrb_count, rra_rb_count, rra_rrb_count);
	if (min == ra_rb_count)
		return (put_to_vector(vector, dupe_r, RARB));
	else if (min == ra_rrb_count)
		return (put_to_vector(vector, 0, RARRB));
	else if (min == rra_rb_count)
		return (put_to_vector(vector, 0, RRARB));
	else
		return (put_to_vector(vector, dupe_rr, RRARRB));
}
