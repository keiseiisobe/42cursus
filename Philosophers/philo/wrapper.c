/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:17:29 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/16 13:53:53 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wrapper_printf(char *str, suseconds_t timestamp_in_ms, int philo_name, int dead_flag)
{
	if (dead_flag == 0)
	{
		printf(str, timestamp_in_ms, philo_name);
		return (CONTINUE);
	}
	else
		return (CANCEL);
}
