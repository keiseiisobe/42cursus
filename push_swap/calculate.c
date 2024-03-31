/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:50:51 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/14 12:35:06 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_variables(t_init *variables, t_lists *lists, int flag)
{
	if (flag == ASC)
	{
		variables->tmp = lists->list_b;
		variables->list_tmp = lists->list_b;
		variables->count_instructions = count_instructions_for_asc;
	}
	else
	{
		variables->tmp = lists->list_a;
		variables->list_tmp = lists->list_a;
		variables->count_instructions = count_instructions_for_desc;
	}
}

t_vector	*update_instructions(t_vector *vector)
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
		return (update_vector(vector, opt.dupe_r, RARB));
	else if (opt.min == opt.ra_rrb_count)
		return (update_vector(vector, 0, RARRB));
	else if (opt.min == opt.rra_rb_count)
		return (update_vector(vector, 0, RRARB));
	else
		return (update_vector(vector, opt.dupe_rr, RRARRB));
}

t_vector	*optimize_instructions(t_lists *lists, t_vector *rotate_vector,
		t_vector *opt_vector, t_init *variables)
{
	t_vector	*opt_vector_tmp;

	init_vector(rotate_vector);
	variables->count_instructions(lists, variables->tmp, rotate_vector);
	opt_vector_tmp = update_instructions(rotate_vector);
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

t_vector	*get_cheapest(t_lists *lists, t_vector *rotate_vector, int flag)
{
	t_init		*variables;
	t_vector	*opt_vector;

	variables = malloc(sizeof(t_init));
	check_error(variables == NULL);
	init_variables(variables, lists, flag);
	opt_vector = NULL;
	while (variables->tmp->next != variables->list_tmp)
	{
		opt_vector = optimize_instructions(lists, rotate_vector,
				opt_vector, variables);
		variables->tmp = variables->tmp->next;
	}
	opt_vector = optimize_instructions(lists, rotate_vector,
			opt_vector, variables);
	free(variables);
	return (opt_vector);
}
