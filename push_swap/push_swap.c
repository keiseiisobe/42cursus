/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 08:59:30 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/24 14:08:29 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}
*/
t_vector	*put_to_vector(t_vector *vector, int dupe, int flag)
{
	t_vector	*opt_vector;

	opt_vector = malloc(sizeof(t_vector));
	init_vector(opt_vector);
	opt_vector->value = vector->value;
	if (flag == RARB)
	{
		opt_vector->ra_count = vector->ra_count - dupe;
		opt_vector->rb_count = vector->rb_count - dupe;
		opt_vector->rr_count = dupe;
		opt_vector->instructions = opt_vector->ra_count + opt_vector->rb_count + opt_vector->rr_count;
	}
	else if (flag == RARRB)
	{
		opt_vector->ra_count = vector->ra_count;
		opt_vector->rrb_count = vector->rrb_count;
		opt_vector->instructions = opt_vector->ra_count + opt_vector->rrb_count;
	}
	else if (flag == RRARB)
	{
		opt_vector->rra_count = vector->rra_count;
		opt_vector->rb_count = vector->rb_count;
		opt_vector->instructions = opt_vector->rra_count + opt_vector->rb_count;
	}
	else if (flag == RRARRB)
	{
		opt_vector->rra_count = vector->rra_count - dupe;
		opt_vector->rrb_count = vector->rrb_count - dupe;
		opt_vector->rrr_count = dupe;
		opt_vector->instructions = opt_vector->rra_count + opt_vector->rrb_count + opt_vector->rrr_count;
	}
	return (opt_vector);
}

t_lists	*move(t_lists *lists, t_vector *vector)
{
	int	i;

	i = 0;
	while (i++ < vector->ra_count)
		rotate(lists, A);
	i = 0;
	while (i++ < vector->rb_count)
		rotate(lists, B);
	i = 0;
	while (i++ < vector->rr_count)
		rotate(lists, R);
	i = 0;
	while (i++ < vector->rra_count)
		reverse_rotate(lists, A);
	i = 0;
	while (i++ < vector->rrb_count)
		reverse_rotate(lists, B);
	i = 0;
	while (i++ < vector->rrr_count)
		reverse_rotate(lists, R);
	return (lists);
}

t_node	*put_smallest_at_the_top(t_lists *lists)
{
	int	flag;

	flag = get_cheapest_instructions_for_asc(lists->list_a);
	if (flag == RA)
		while (lists->list_a->value > lists->list_a->prev->value)
			rotate(lists, A);
	else
	{
		while (lists->list_a->value > lists->list_a->prev->value)
			reverse_rotate(lists, A);
	}
	return (lists->list_a);
}

t_node	*put_biggest_at_the_top(t_lists *lists)
{
	int	flag;

	flag = get_cheapest_instructions_for_desc(lists->list_b);
	if (flag == RB)
		while (lists->list_b->value < lists->list_b->prev->value)
			rotate(lists, B);
	else
	{
		while (lists->list_b->value < lists->list_b->prev->value)
			reverse_rotate(lists, B);
	}
	return (lists->list_b);
}

t_node	*handle_stack_b(t_lists *lists, int num_of_args)
{
	t_vector	*rotate_vector;
	t_vector	*opt_vector;
	int			i;

	i = 0;
	while (i++ < num_of_args - 6)
	{
		rotate_vector = malloc(sizeof(t_vector));
		opt_vector = get_cheapest(lists, rotate_vector, DESC);
		lists = move(lists, opt_vector);
		lists = push_b(lists);
		free(rotate_vector);
		free(opt_vector);
	}
	lists->list_b = put_biggest_at_the_top(lists);
	return (lists->list_b);
}

t_node	*handle_stack_a(t_lists *lists, int num_of_args)
{
	t_vector	*rotate_vector;
	t_vector	*opt_vector;
	int	i;

	i = 0;
	while (i++ < num_of_args - 3)
	{
		rotate_vector = malloc(sizeof(t_vector));
		opt_vector = get_cheapest(lists, rotate_vector, ASC);
		lists = move(lists, opt_vector);
		lists = push_a(lists);
		free(rotate_vector);
		free(opt_vector);
	}
	lists->list_a = put_smallest_at_the_top(lists);
	return (lists->list_a);
}

t_node	*sort(t_lists *lists, int num_of_args, int flag)
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

t_node	*push_swap(t_lists *lists, int num_of_args)
{
	lists->list_b = NULL;
	if (num_of_args < 4)
		return (sort(lists, num_of_args, LESS_THAN_4));
	if (num_of_args < 6)
		return (sort(lists, num_of_args, LESS_THAN_6));
//------------------------sort-------------------------
	pb_3_nums(lists);
	sort(lists, num_of_args, DESC_THREE);
	sort(lists, num_of_args, DESC);
	sort(lists, num_of_args, ASC_THREE);
	sort(lists, num_of_args, ASC);
	lists->list_a = put_smallest_at_the_top(lists); // is return value needed ???
/*
//---------printf for testing list_b-------------
	t_node	*tmp_b;
	tmp_b = lists->list_b;

	if (tmp_b)
	{
		while (tmp_b && (tmp_b->next != lists->list_b))
		{
			printf("list_b : value is %d, address is %p, prev is %p, next is %p\n", tmp_b->value, tmp_b, tmp_b->prev, tmp_b->next);
			tmp_b = tmp_b->next;
		}
		printf("list_b : value is %d, address is %p, prev is %p, next is %p\n\n\n", tmp_b->value, tmp_b, tmp_b->prev, tmp_b->next);
	}
*/
	free_list(lists->list_b);
	return (lists->list_a);
}

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

int main(int argc, char *argv[])
{
	t_arg	*arg;
	t_lists	*lists;

	arg = arg_check(argc, argv);
//------put arg to list-------
	lists = malloc(sizeof(t_lists));
	lists->list_a = init_list(arg);
//--------------sort (push_swap)------------------
	if (is_sorted(lists->list_a) == true)
		exit(0);
	lists->list_a = push_swap(lists, arg->num_of_args); // is retrun value needed ???
/*
//--------printf for testing list_a--------------
	t_node	*tmp_a;
	tmp_a = lists->list_a;
	printf("\n\n\n");
	if (tmp_a)
	{
		while (tmp_a->next != lists->list_a)
		{
			printf("list_a : value is %d, address is %p, prev is %p, next is %p\n", tmp_a->value, tmp_a, tmp_a->prev, tmp_a->next);
			tmp_a = tmp_a->next;
		}
		printf("list_a : value is %d, address is %p, prev is %p, next is %p\n\n\n", tmp_a->value, tmp_a, tmp_a->prev, tmp_a->next);
	}
*/
	free_list(lists->list_a);
	free(lists);
	free(arg);
}

