/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:17:29 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/31 10:24:39 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wrapper_printf(char *str, size_t timestamp_in_ms,
		t_philo_info *philo, int dead_flag)
{
	if (dead_flag == 0)
	{
		printf(str, timestamp_in_ms, philo->name);
		return (CONTINUE);
	}
	else
		return (CANCEL);
}
