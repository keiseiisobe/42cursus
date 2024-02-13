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

typedef struct s_stack {
	void*	prev;
	int	value;
	void*	next;
} t_stack;

typedef struct s_arg {
	int	argc;
	int	*argv[];
	int	arg_num;
} t_arg;

void	arg_check(int argc, char *argv[])
{
//	if (ft_split[i][1] != NULL && argv[i + 1] != NULL)
//		invalid arg (case 1)
}

int	*convert_args_to_int_arr(int argc, char *argv[], int *arg_num)
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

int	*put_args_to_stack_A(int argc, char *argv[])
{
//-------convert args to int_ptr--------
	int *args = convert_args_to_int_arr(argc, argv[], &arg_num);
//------put args to each nodes in list--------
//	t_stack *list = NULL;
//	while (i < arg_num)
//	{
//		t_stack *stack;
//		stack = malloc();
//		stack->value = args[];
//		stack->next = NULL;
//		if (list == NULL)
//			stack->prev = NULL;
//		else
//		{
//			t_stack tmp = list;
//			while (tmp->next)
//			{
//				tmp = tmp->next;
//			}
//			tmp->next = stack;
//		}
//	}
}

void	sort_small_nums(t_stack *list)
{

}

void	sort_big_nums(t_stack *list)
{

}

int main(int argc, char *argv[])
{
	t_arg arg;
	arg = malloc(); // it is useful in throwing "arg_num" to each function.
//--------arg check--------------
//	no arg->invaid arg, too many args->time out?.
//
//	already sorted, arg aren't intgers, bigger than int, duplicate, agrs with "".
//	./push_swap "2 0" 1 3   this kind of arg will cause Error(case 1),
//	but ./push_swap "2" 0 1 3 will be permitted.
//	and ./push_swap "2 0 1 3" will be permitted.
	arg_check(argc, argv[]);
//------put arg to stack A-------
	void*	list = put_args_to_stack_A(int argc, char *argv[])
//--------------sort------------------
//	if (arg_num == 6???)
		sort_small_nums(list);
	else
		sort_big_nums(list);
}



