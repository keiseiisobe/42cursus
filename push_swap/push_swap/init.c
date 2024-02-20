/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:02:00 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/20 09:29:06 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_num_of_args(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

int	*convert_args_to_int_arr(t_arg *arg)
{
	char	**arg_tmp;
	int		*nums;
	int		i;

	if (arg->argc == 2)
	{
		arg_tmp = ft_split(arg->argv[1], ' ');
		check_error(arg_tmp == NULL);
		arg->num_of_args = count_num_of_args(arg_tmp);
		nums = malloc(arg->num_of_args * sizeof(int));
		i = 0;
		while(i < arg->num_of_args)
		{
			nums[i] = ft_atoi(arg_tmp[i]);
			i++;
		}
		i = 0;
		while (arg_tmp[i])
			free(arg_tmp[i++]);
		free(arg_tmp);
	}
	else
	{
		arg->num_of_args = count_num_of_args(arg->argv) - 1;
		nums = malloc(arg->num_of_args * sizeof(int));
		i = 0;
		while (i < arg->num_of_args)
		{
			nums[i] = ft_atoi(arg->argv[i + 1]);
			i++;
		}
	}
	return (nums);
}

t_node	*create_first_node(t_node *node, t_node *list)
{
	printf("head is %p\n", node);
	node->prev = node;
	node->next = node;
	list = node;
	return (list);
}

t_node	*init_list(t_arg *arg)
{
	int		*nums;
	int		i;
	t_node	*list_a;
	t_node	*tmp;

//-------convert args to int_ptr--------
	nums = convert_args_to_int_arr(arg);
//------put args to each nodes in list--------
//	list = malloc(sizeof(t_list));
	list_a = NULL;
	i = 0;
	while (i < arg->num_of_args)
	{
		t_node	*node;
		node = malloc(sizeof(t_node));
		node->value = nums[i];
		if (list_a == NULL)
			list_a = create_first_node(node, list_a);
		else
		{
			tmp = list_a;
			while (tmp->next != list_a)
				tmp = tmp->next;
//			tmp->prev = node;
			tmp->next = node;
			node->prev = tmp;
			node->next = list_a;
		}
		i++;
	}
	free(nums);
	return (list_a);
}

