/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:16:08 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/20 13:08:20 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*swap_a(t_node *list)
{
	t_node	*list_tmp;
	t_node	*tmp;

	if (list == list->next->next)
	{
		list = list->next;
		return (list);
	}
	list_tmp = list;
	list = list->next;
	list_tmp->next = list->next;
	list_tmp->next->next->prev = list_tmp;
	list->next = list_tmp;
	list_tmp->prev = list;
	tmp = list;
	while (tmp->next != list_tmp)
		tmp = tmp->next;
	tmp->next = list;
	list->prev = tmp;
	return (list);
}
/*
	first_tmp = list;
	second_tmp = first_tmp->next;
	third_tmp = second_tmp->next;
	second_tmp->next = first_tmp;
	first_tmp->prev = second_tmp;
	first_tmp->next = third_tmp;
	third_tmp->prev = first_tmp;
*/

/*
swap_b()
{

}

swap_a_and_b()
{

}
push_a()
{

}
*/
t_lists	*push_b(t_lists *lists)
{
	t_node	*list_a_tmp;
	t_node	*tmp;

	list_a_tmp = lists->list_a;
	if (lists->list_a == lists->list_a->next)
		lists->list_a = NULL;
	else
	{
		lists->list_a = lists->list_a->next;
		tmp = lists->list_a;
		while (tmp->next != list_a_tmp)
			tmp = tmp->next;
		lists->list_a->prev = tmp;
		tmp->next = lists->list_a;
	}

	if (lists->list_b == NULL)
	{
		lists->list_b = create_first_node(list_a_tmp, lists->list_b);
		lists->list_b->value = list_a_tmp->value;
	}
	else
	{
		list_a_tmp->next = lists->list_b;
		lists->list_b->prev = list_a_tmp;
		tmp = lists->list_b;
		while (tmp->next != lists->list_b)
			tmp = tmp->next;
		list_a_tmp->prev = tmp;
		tmp->next = list_a_tmp;
		lists->list_b = list_a_tmp;
	}
	printf("pb\n");
	return (lists);
}
/*
rotate_a()
{

}

rotate_b()
{

}

rotate_a_and_b()
{

}

reverse_rotate_a()
{

}

reverse_rotate_b()
{

}

reverse_rotate_a_and_b()
{

}
*/
