/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:01:50 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/31 10:24:53 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_forks(t_philo_info *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->data->dead_flag_key);
	if (wrapper_printf("%zu %d has taken a fork\n", get_current_time(philo->data
				->start_time), philo, philo->data->dead_flag) == CANCEL)
	{
		pthread_mutex_unlock(&philo->data->dead_flag_key);
		pthread_mutex_unlock(&philo->fork);
		return (CANCEL);
	}
	pthread_mutex_unlock(&philo->data->dead_flag_key);
	if (handle_one_philo(philo) == CANCEL)
		return (CANCEL);
	pthread_mutex_lock(&philo->next->fork);
	pthread_mutex_lock(&philo->data->dead_flag_key);
	if (wrapper_printf("%zu %d has taken a fork\n", get_current_time(philo->data
				->start_time), philo, philo->data->dead_flag) == CANCEL)
	{
		pthread_mutex_unlock(&philo->data->dead_flag_key);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		return (CANCEL);
	}
	pthread_mutex_unlock(&philo->data->dead_flag_key);
	return (CONTINUE);
}

int	ft_eat(t_philo_info *philo)
{
	update_time_to_start_eating(philo);
	pthread_mutex_lock(&philo->data->dead_flag_key);
	if (wrapper_printf("%zu %d is eating\n",
			get_current_time(philo->data->start_time),
			philo, philo->data->dead_flag) == CANCEL)
	{
		pthread_mutex_unlock(&philo->data->dead_flag_key);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		return (CANCEL);
	}
	pthread_mutex_unlock(&philo->data->dead_flag_key);
	ft_msleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_lock(&philo->updated_time_key);
	philo->num_of_times_of_eating++;
	pthread_mutex_unlock(&philo->updated_time_key);
	return (CONTINUE);
}

int	ft_sleep(t_philo_info *philo)
{
	pthread_mutex_lock(&philo->data->dead_flag_key);
	if (wrapper_printf("%zu %d is sleeping\n",
			get_current_time(philo->data->start_time),
			philo, philo->data->dead_flag) == CANCEL)
	{
		pthread_mutex_unlock(&philo->data->dead_flag_key);
		return (CANCEL);
	}
	pthread_mutex_unlock(&philo->data->dead_flag_key);
	ft_msleep(philo->data->time_to_sleep);
	return (CONTINUE);
}

int	ft_think(t_philo_info *philo)
{
	pthread_mutex_lock(&philo->data->dead_flag_key);
	if (wrapper_printf("%zu %d is thinking\n",
			get_current_time(philo->data->start_time),
			philo, philo->data->dead_flag) == CANCEL)
	{
		pthread_mutex_unlock(&philo->data->dead_flag_key);
		return (CANCEL);
	}
	pthread_mutex_unlock(&philo->data->dead_flag_key);
	return (CONTINUE);
}

void	*philo_do(void *philo_info)
{
	t_philo_info	*philo;

	philo = (t_philo_info *)philo_info;
	pthread_mutex_lock(&philo->updated_time_key);
	philo->time_to_start_eating = get_current_time(0);
	pthread_mutex_unlock(&philo->updated_time_key);
	check_if_odd_philo(philo);
	while (1)
	{
		if (ft_take_forks(philo) == CANCEL)
			break ;
		if (ft_eat(philo) == CANCEL)
			break ;
		if (ft_sleep(philo) == CANCEL)
			break ;
		if (ft_think(philo) == CANCEL)
			break ;
	}
	return (NULL);
}
