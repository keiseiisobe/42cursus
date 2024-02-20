/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 08:59:30 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/20 13:08:23 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}

void	pb_3_nums(t_lists *lists)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		lists = push_b(lists);
		i++;
	}
}

t_node	*handle_3_nums(t_node *list_a)
{
	return (list_a);
}

t_node	*handle_less_than_4_nums(t_node *list_a, int num_of_args)
{
	if (num_of_args == 2)
		list_a = swap_a(list_a);
	else if (num_of_args == 3)
		list_a = handle_3_nums(list_a);
	return (list_a);
}

t_node	*sort_nums(t_lists *lists, int num_of_args)
{
//-------initialize stack B list------------
//	check if num_of_args is < 4, then don"t push, sort!)
	if (num_of_args < 4)
	{
		lists->list_a = handle_less_than_4_nums(lists->list_a, num_of_args);
		return (lists->list_a);
	}
	lists->list_b = NULL;
//	pb_3_nums(lists);
	lists->list_a = swap_a(lists->list_a);
//	handle_3_nums();

//---------printf for testing-------------
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
		printf("list_a : value is %d, address is %p, prev is %p, next is %p\n", tmp_a->value, tmp_a, tmp_a->prev, tmp_a->next);
	}
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

//	sort_stack_b_in_descending_order();
//	sort_stack_a();

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
	sort_nums(lists, arg->num_of_args);

	free_list(lists->list_a);
	free(lists);
	free(arg);
}

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

void  sort_stack_b_in_decending_order()
{

}

void  handle_three_nums()
{

}

void  sort_stack_a()
{

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







/*
void	sort_big_nums(t_stack *list)
{
// coordinate compression is needed.

// divide numbers in stack A by 2, then move smaller numbers to stack B.
// divide smaller numbers in stack A by 2, then move smaller numbers to stack B. (same as before)
// (To minimize num of instructions, when search enough number, stop searching.)
//  (ex.   N = 100: At first, we divide 100 by 2, then we put 50 numbers to stack B.
//   So, if elements of stack A or B is 50, stop searching, and rotate back the element of stack A.)

// if you can't divide anymore (num of devided elements is <= 2, compare two number and swap them.)
// if num of devided elements is = 3, move smallest number to stack B, and compare rest of two number,
// and, push back smallest number to stack A.

// rotate these procedure by using recursive ???
// the parameters in recursive function are the array of numbers which was devided by previous function and
// the number of divided number.


// keep devided number in memory,
// it will be efficient when searching array unless you're already get enough number.
// ex.   1 3 2 4 6 5   we want divide these number to 465 and 231, and move 132 to stack B.
// then when you read until 2, you have already done. so you don't need to "ra" and "rra" 465.
// -> a little optimization
}
*/
