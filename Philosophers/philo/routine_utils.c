/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:10:34 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/31 10:24:12 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_one_philo(t_philo_info *philo)
{
	if (&philo->next->name == &philo->name)
	{
		pthread_mutex_unlock(&philo->fork);
		return (CANCEL);
	}
	return (CONTINUE);
}

void	update_time_to_start_eating(t_philo_info *philo)
{
	pthread_mutex_lock(&philo->updated_time_key);
	philo->time_to_start_eating = get_current_time(0);
	pthread_mutex_unlock(&philo->updated_time_key);
}

void	check_if_odd_philo(t_philo_info *philo)
{
	if (philo->name % 2 == 0)
		ft_msleep(philo->data->time_to_eat / 2);
}

size_t	get_current_time(size_t start_time)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	if (start_time == 0)
		return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
	return ((tp.tv_sec * 1000 + tp.tv_usec / 1000) - start_time);
}

void	ft_msleep(size_t ms)
{
	size_t	start;

	start = get_current_time(0);
	while (get_current_time(0) - start < ms)
		usleep(500);
	return ;
}
