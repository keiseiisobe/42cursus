/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 08:59:30 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/23 17:54:18 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}

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

/*
void	update_vector(t_vector *vector, t_vector *tmp_vector)
{
	t_vector *tmp;

	tmp = tmp_vector;
	tmp_vector = vector;
	vector = tmp;
	free(tmp_vector);
	return (vector);
}
*/

t_lists	*move_the_one(t_lists *lists, t_vector *vector)
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

	flag = get_cheapest_instructions(lists->list_a);
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
/*
void	sort_stack_b_in_desc_order(t_lists *list, int num_of_args)
{
	t_vector	*rotate_vector;
	t_vector	*opt_vector;
	int			i;

	i = 0;
	while (i++ < num_of_args - 6)
	{
		rotate_vector = malloc(sizeof(t_vector));
		opt_vector = search_cheapest_one(lists, rotate_vector, DESC);
		lists = move_the_one(lists, opt_vector, DESC);
		lists->list_b = put_biggest_at_the_top(lists);
		free(rotate_vector);
		free(opt_vector);
	}
}

void	sort_stack_a(t_lists *lists, int num_of_args)
{
	t_vector	*rotate_vector;
	t_vector	*opt_vector;
	int	i;

	i = 0;
	while (i++ < num_of_args - 3)
	{
		rotate_vector = malloc(sizeof(t_vector));
		opt_vector = search_cheapest_one(lists, rotate_vector, ASC);
		lists = move_the_one(lists, opt_vector, ESC);
		lists->list_a = put_biggest_at_the_top(lists);
		free(rotate_vector);
		free(opt_vector);
	}
}
*/

t_node	*sort_nums(t_lists *lists, int num_of_args)
{
	lists->list_b = NULL;
//-------check if num_of_args is < 4, then don"t push, sort!)--------
	if (num_of_args < 4)
		return (handle_less_than_4_nums(lists, num_of_args));
//------check if num_of_arg is < 6, then push_b until num_of_nodes in stack_a is 3, then sort and push_a!-----
	if (num_of_args < 6)
		return (handle_less_than_6_nums(lists, num_of_args));
//------------------------sort-------------------------
//-------initialize stack B list------------
	pb_3_nums(lists);
	handle_3_nums(lists, DESC);
	sort_stack_b_in_desc_order(lists, num_of_args);
	sort_stack_a(lists, num_of_args);
	lists->list_a = put_smallest_at_the_top(lists);
//------------------------------------------------------

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
//-----------------------------------------

	free_list(lists->list_b);
	return (lists->list_a);
}

int main(int argc, char *argv[])
{
	t_arg	*arg;
	t_lists	*lists;

	arg = arg_check(argc, argv);
//------put arg to list-------
	lists = malloc(sizeof(t_lists));
	lists->list_a = init_list(arg);
//--------------sort------------------
	lists->list_a = sort_nums(lists, arg->num_of_args);

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
//-----------------------------------------------

	free_list(lists->list_a);
	free(lists);
	free(arg);
}

/*
search_cheapest_one()
{
	t_node		*tmp_a;
	t_node		*tmp_b;
	t_vector	*tmp_vector;

//while
//{
//--------check the cheapest way to put the nums of list_a and list_b one by one----------
//	ex.
//	list_a = "1 3 4 5 6 9 11 12 13 14 15
//	list_b = "7 8 10 2"
//	best solution to get 2 is ra rrb.
//	ex.
//	list_a = "1 3 4 5 6 9 11 12 13 14 15
//	list_b = "7 2 8 10"
//	best solution to get 2 is rr.
//--------loop until list_b->next == list_b head------------
	vector->instructions = 0;
	tmp_b = lists->list_b;
	while (tmp_b != lists->list_b)
	{
		tmp_vector = malloc(sizeof(t_vector));
		init_vector(tmp_vector);
//------count num of instructions of each num in stack B------
		tmp_vector->instructions = count_instructions(lists, tmp_b, tmp_vector) + COUNT_ONE_PUSH;
//		r_instructions = ra_count + rb_count - duplicating;
//		rr_instructions = ra_count + rb_count - duplicating;
//		num_of_instructions = (r_instructions <= rr_instructions ? r_instructions : rr_instructions);



//-------if you get the best solution, then put it to the vector !!!---------
//
//------update the best solution--------
	if (best_solution > current_solution_for_current_node_value)
		update best solution;
//}

//
//------if num_of_instruction is fewer than before one, then update !!!-----------
		if (vector->instructions == 0 || vector->instructions > tmp_vector->instructions)
			vector = update_vector(vector, tmp_vector);
		else
			free(tmp_vector);
		tmp_b = tmp_b->next;
	}
}
*/

/*
// when using turkey algorithm...

// coordinate compression is needed.

// put first three numbers to stack B.
// solve by three numbers sorting.(create three numbers sorting function.)

// (process 1)
// calculate we should put which number to stack B.
// (search which number is cheapest in terms of num of instruction.)
// In calculation, some optimization is needed.
// (ex.   in stack A : ra ra ra   in stack B : rb rb rb   then, you should "rr rr rr",
int count_ra()
{
  
//  if duplicate instructions, use rr or rrr.
}

int  count_instructions()
{
  ra_count = count_ra();
  rra_count = rount_rra();
  sum_count = ra_count + rra_count;
  return (sum_count);
}

void search_cheapest_num()
{
  while (num_of_stack_a)
  {
    count = count_instructions();
    push_to_stack_b();
  }
}

//  and you can reduce three instruction.)
// use instruction to put number in correct position for next step.
// put number to the top of stack B.

// continue these procedure until num of stack A is three.
// (because three numbers is easy to sort.)

// check if the top of stack B is the biggest number in stack B.

// sort numbers in stack A.
// put the biggest number to the top of stack A.
// do the same process of (process 1)

// After that all process,
// check if the top of number in stack A is smallest in stack A.

*/

