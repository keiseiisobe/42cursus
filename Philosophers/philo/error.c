/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:44:01 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/13 16:27:01 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_error(bool is_error, int flag)
{
	if (is_error == true)
	{
		printf("Error: ");
		if (flag == MALLOC)
			printf("Memory allocation failed.\n");
		return (true);
	}
	return (false);
}
