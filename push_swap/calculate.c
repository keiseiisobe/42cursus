/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:50:51 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/24 20:03:33 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_num_of_args(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

t_vector	*get_cheapest(t_lists *lists, t_vector *rotate_vector, int flag)
{
	if (flag == ASC)
		return (get_cheapest_for_asc(lists, rotate_vector));
	else
		return (get_cheapest_for_desc(lists, rotate_vector));
}

t_vector	*optimize_instructions(t_vector *vector)
{
	t_opt	opt;

	opt.dupe_r = check_dupe(vector->ra_count, vector->rb_count);
	opt.ra_rb_count = vector->ra_count + vector->rb_count - opt.dupe_r;
	opt.ra_rrb_count = vector->ra_count + vector->rrb_count;
	opt.rra_rb_count = vector->rra_count + vector->rb_count;
	opt.dupe_rr = check_dupe(vector->rra_count, vector->rrb_count);
	opt.rra_rrb_count = vector->rra_count + vector->rrb_count - opt.dupe_r;
	opt.min = get_min(opt.ra_rb_count, opt.ra_rrb_count, opt.rra_rb_count,
			opt.rra_rrb_count);
	if (opt.min == opt.ra_rb_count)
		return (put_to_vector(vector, opt.dupe_r, RARB));
	else if (opt.min == opt.ra_rrb_count)
		return (put_to_vector(vector, 0, RARRB));
	else if (opt.min == opt.rra_rb_count)
		return (put_to_vector(vector, 0, RRARB));
	else
		return (put_to_vector(vector, opt.dupe_rr, RRARRB));
}
