/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:49:30 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/17 12:31:42 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pthread_join_all(t_philo_info *philos, int num_of_philos, pthread_t monitor)
{
	int				i;
	t_philo_info	*tmp;

	pthread_join(monitor, NULL);
	i = 1;
	tmp = philos;
	while (i <= num_of_philos)
	{
		pthread_join(tmp->thread_id, NULL);
		tmp = tmp->next;
		i++;
	}
}
