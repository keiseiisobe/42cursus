/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:44:01 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/17 11:07:08 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_error(bool is_error, int error_type, int error_msg)
{
	if (is_error == true)
	{
		printf("Error: ");
		if (error_type == ARG)
		{
			printf("Invalid args");
			if (error_msg == ARGC)
				printf(" : Only 4 or 5 arguments are available.");
			else if (error_msg == DIGIT)
				printf(" : Only digits are available (Of course, '-' '+' are unavailable).");
			else if (error_msg == MINUS)
				printf(" : Less than 1 is unavailable for [num_of_philo] and [num_of_times_philo_must_eat]");
			else if (error_msg == TOO_MANY_PHILOS)
				printf(" : 200 philos is max.");
			else if (error_msg == TIME_MIN)
				printf(" : Each time must not be less than 60ms.");
			else if (error_msg == MAX)
				printf(" : More than INT_MAX is unavailable.");
		}
		else if (error_type == MALLOC)
			printf("Memory allocation failed");
		printf("\n");
		return (true);
	}
	return (false);
}
