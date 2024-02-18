/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 08:59:30 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/13 11:15:40 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_args_to_int_arr(t_arg *arg)
{
//	int	*args_arr;
//	if (argc == 2)
//		arg_tmp = ft_split(argv[1]);
//		while()
//			args_arr[] = ft_atoi(arg_tmp[]);
//	else
//		while (argv[])
//			args_arr[] = ft_atoi(argv[])
	arg->arg_num = ;
}

void	*init_list(t_arg *arg)
{
  int *arr;
  void  *list;
  int i;
  t_node  *tmp;
//-------convert args to int_ptr--------
	arr = convert_args_to_int_arr(arg);
//------put args to each nodes in list--------
	list = NULL;
  i = 0;
	while (i < arg->arg_num)
	{
		t_node *node;
		node = malloc(sizeof(t_node));
		node->value = arr[i];
		node->next = NULL;
		if (list == NULL)
			node->prev = NULL;
		else
		{
			tmp = list;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = node;
      node->prev = tmp;
		}
    i++:
	}
  return (list);
}

void  sort_nums()
{
  push_three_nums_to_stack_b();
  handle_three_nums();
  sort_stack_b_in_decending_order();
  sort_stack_a();
}

int main(int argc, char *argv[])
{
  t_arg *arg;
  void  *list;

	arg = arg_check(argc, argv[]);
//------put arg to stack A-------
	list = init_list(arg)
//--------------sort------------------
  sort_nums(list);
  free(arg);
}


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
