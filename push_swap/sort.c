/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:37:37 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/11 13:05:36 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_lists	*sort(t_lists *lists, int num_of_args, int flag)
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
