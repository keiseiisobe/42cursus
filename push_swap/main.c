/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:14:03 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/24 21:31:08 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_arg	*arg;
	t_lists	*lists;

	arg = arg_check(argc, argv);
	lists = malloc(sizeof(t_lists));
	lists->list_a = init_list(arg);
	if (is_sorted(lists->list_a) == true)
		exit(0);
	push_swap(lists, arg->num_of_args);
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
