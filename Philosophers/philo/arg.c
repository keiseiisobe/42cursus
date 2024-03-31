/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:38:33 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/20 15:45:53 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	args_are_invalid(int argc, char *argv[])
{
	if (check_error(argc != 5 && argc != 6, ARG, ARGC))
		return (true);
	if (check_error(args_are_not_digit(argv), ARG, DIGIT))
		return (true);
	if (check_error(is_more_than(INT_MAX, argc, argv), ARG, MAX))
		return (true);
	if (check_error(is_less_than(1, argc, argv), ARG, MINUS))
		return (true);
	if (check_error(is_more_than(200, argc, argv), ARG, TOO_MANY_PHILOS))
		return (true);
	if (check_error(is_less_than(60, argc, argv), ARG, TIME_MIN))
		return (true);
	return (false);
}

void	init_arg_data(t_data *data, int argc, char *argv[])
{
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		data->num_of_times_each_philo_must_eat = 0;
}

int	handle_args(t_data *data, int argc, char *argv[])
{
	if (args_are_invalid(argc, argv) == true)
		return (RETURN_FAILURE);
	init_arg_data(data, argc, argv);
	return (RETURN_SUCCESS);
}
