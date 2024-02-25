/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:02:00 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/25 16:11:39 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_args_for_single_arg(t_arg *arg)
{
	char	**arg_tmp;
	int		*nums;
	int		i;

	arg_tmp = ft_split(arg->argv[1], ' ');
	check_error(arg_tmp == NULL);
	arg->num_of_args = count_num_of_args(arg_tmp);
	nums = malloc(arg->num_of_args * sizeof(int));
	i = 0;
	while (i < arg->num_of_args)
	{
		nums[i] = ft_atoi(arg_tmp[i]);
		i++;
	}
	i = 0;
	while (arg_tmp[i])
		free(arg_tmp[i++]);
	free(arg_tmp);
	return (nums);
}

int	*convert_args_for_multiple_arg(t_arg *arg)
{
	int		*nums;
	int		i;

	arg->num_of_args = count_num_of_args(arg->argv) - 1;
	nums = malloc(arg->num_of_args * sizeof(int));
	i = 0;
	while (i < arg->num_of_args)
	{
		nums[i] = ft_atoi(arg->argv[i + 1]);
		i++;
	}
	return (nums);
}

int	*convert_args_to_int_arr(t_arg *arg)
{
	if (arg->argc == 2)
		return (convert_args_for_single_arg(arg));
	else
		return (convert_args_for_multiple_arg(arg));
}

t_node	*create_first_node(t_node *node)
{
	t_node	*list;

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
	t_node	*node;

	nums = convert_args_to_int_arr(arg);
	i = 0;
	node = malloc(sizeof(t_node));
	node->value = nums[i++];
	list_a = create_first_node(node);
	while (i < arg->num_of_args)
	{
		node = malloc(sizeof(t_node));
		node->value = nums[i++];
		tmp = list_a;
		while (tmp->next != list_a)
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
		node->next = list_a;
		list_a->prev = node;
	}
	free(nums);
	return (list_a);
}
