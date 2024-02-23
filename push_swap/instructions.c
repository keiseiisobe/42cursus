/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:16:08 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/23 12:03:52 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*swap(t_node *list, int flag)
{
	t_node	*first_tmp = list;
	t_node	*second_tmp = first_tmp->next;
	t_node	*third_tmp = second_tmp->next;
	t_node	*before_tmp = first_tmp->prev;
//	printf("first_tmp is %p\n", first_tmp);
//	printf("second_tmp is %p\n", second_tmp);
//	printf("third_tmp is %p\n", third_tmp);
//	printf("before_tmp is %p\n", before_tmp);

	if (flag == A)
		write(1, "sa\n", 3);
	else if (flag == B)
		write(1, "sb\n", 3);
	if (list == list->next->next)
		return (list->next);
	second_tmp->next = first_tmp;
	second_tmp->prev = before_tmp;
	first_tmp->prev = second_tmp;
	first_tmp->next = third_tmp;
	third_tmp->prev = first_tmp;
	before_tmp->next = second_tmp;
	return (second_tmp);
}

t_lists	*push_a(t_lists *lists)
{
	t_node	*list_b_tmp;
	t_node	*tmp;

	list_b_tmp = lists->list_b;
	if (lists->list_b == lists->list_b->next)
		lists->list_b = NULL;
	else
	{
		lists->list_b = lists->list_b->next;
		tmp = lists->list_b;
		while (tmp->next != list_b_tmp)
			tmp = tmp->next;
		lists->list_b->prev = tmp;
		tmp->next = lists->list_b;
	}

	list_b_tmp->next = lists->list_a;
	lists->list_a->prev = list_b_tmp;
	tmp = lists->list_a;
	while (tmp->next != lists->list_a)
		tmp = tmp->next;
	list_b_tmp->prev = tmp;
	tmp->next = list_b_tmp;
	lists->list_a = list_b_tmp;

	write(1, "pa\n", 3);
	return (lists);
}

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
	write(1, "pb\n", 3);
	return (lists);
}

void	rotate(t_lists *lists, int flag)
{
	if (flag == A)
	{
		write(1, "ra\n", 3);
		lists->list_a = lists->list_a->next;
	}
	else if (flag == B)
	{
		write(1, "rb\n", 3);
		lists->list_b = lists->list_b->next;
	}
	else if (flag == R)
	{
		write(1, "rr\n", 3);
		lists->list_a = lists->list_a->next;
		lists->list_b = lists->list_b->next;
	}
}

void	reverse_rotate(t_lists *lists, int flag)
{
	if (flag == A)
	{
		write(1, "rra\n", 4);
		lists->list_a = lists->list_a->prev;
	}
	else if (flag == B)
	{
		write(1, "rrb\n", 4);
		lists->list_b = lists->list_b->prev;
	}
	else if (flag == R)
	{
		write(1, "rrr\n", 4);
		lists->list_a = lists->list_a->prev;
		lists->list_b = lists->list_b->prev;
	}
}
