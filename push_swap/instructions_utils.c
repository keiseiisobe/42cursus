/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:46:37 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/25 16:13:52 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_3_times(t_lists *lists)
{
	int	i;

	i = 0;
	while (i++ < 3)
		push_b(lists);
}

t_node	*get_end_of_list(t_node *list, t_node *list_tmp)
{
	t_node	*tmp;

	tmp = list;
	while (tmp->next != list_tmp)
		tmp = tmp->next;
	return (tmp);
}

void	init_list_b(t_lists *lists, t_node *list_a_tmp)
{
	lists->list_b = create_first_node(list_a_tmp);
	lists->list_b->value = list_a_tmp->value;
}
