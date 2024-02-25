/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:14:07 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/25 16:24:14 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_rarb_vector(t_vector *opt_vector, t_vector *vector, int dupe)
{
	opt_vector->ra_count = vector->ra_count - dupe;
	opt_vector->rb_count = vector->rb_count - dupe;
	opt_vector->rr_count = dupe;
	opt_vector->instructions = opt_vector->ra_count
		+ opt_vector->rb_count + opt_vector->rr_count;
}

void	update_rrarb_vector(t_vector *opt_vector, t_vector *vector)
{
	opt_vector->rra_count = vector->rra_count;
	opt_vector->rb_count = vector->rb_count;
	opt_vector->instructions = opt_vector->rra_count + opt_vector->rb_count;
}

void	update_rarrb_vector(t_vector *opt_vector, t_vector *vector)
{
	opt_vector->ra_count = vector->ra_count;
	opt_vector->rrb_count = vector->rrb_count;
	opt_vector->instructions = opt_vector->ra_count + opt_vector->rrb_count;
}

void	update_rrarrb_vector(t_vector *opt_vector, t_vector *vector, int dupe)
{
	opt_vector->rra_count = vector->rra_count - dupe;
	opt_vector->rrb_count = vector->rrb_count - dupe;
	opt_vector->rrr_count = dupe;
	opt_vector->instructions = opt_vector->rra_count
		+ opt_vector->rrb_count + opt_vector->rrr_count;
}
