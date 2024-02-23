/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:54:35 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/20 10:05:38 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *list)
{
	t_node	*tmp;
	t_node	*tmp_next;
//-------free list_a-----------
	tmp = list;
	if (tmp)
	{
		while (tmp->next != list)
		{
			tmp_next = tmp->next;
			free(tmp);
			tmp = tmp_next;
		}
		free(tmp);
	}
}
