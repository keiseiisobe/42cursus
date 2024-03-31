/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:52:19 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/31 11:35:38 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_someone_dead(t_philo_info *tmp)
{
	size_t	death_time;

	pthread_mutex_lock(&tmp->updated_time_key);
	death_time = tmp->time_to_start_eating + tmp->data->time_to_die;
	pthread_mutex_unlock(&tmp->updated_time_key);
	if (get_current_time(0) >= death_time)
	{
		pthread_mutex_lock(&tmp->data->dead_flag_key);
		printf("%zu %d died\n", get_current_time(tmp->data->start_time),
			tmp->name);
		tmp->data->dead_flag = 1;
		pthread_mutex_unlock(&tmp->data->dead_flag_key);
		return (true);
	}
	return (false);
}

bool	did_everyone_eat_min_times(t_philo_info *tmp)
{
	static int	num_of_philos_achieved = 0;

	pthread_mutex_lock(&tmp->updated_time_key);
	if (tmp->num_of_times_of_eating
		>= tmp->data->num_of_times_each_philo_must_eat)
		num_of_philos_achieved++;
	else
		num_of_philos_achieved = 0;
	pthread_mutex_unlock(&tmp->updated_time_key);
	if (num_of_philos_achieved == tmp->data->num_of_philos)
	{
		pthread_mutex_lock(&tmp->data->dead_flag_key);
		tmp->data->dead_flag = 1;
		pthread_mutex_unlock(&tmp->data->dead_flag_key);
		return (true);
	}
	return (false);
}

void	*monitor_the_end_of_simulation(void *arg)
{
	t_philo_info	*tmp;
	t_philo_info	*philos;

	philos = (t_philo_info *)arg;
	tmp = philos;
	ft_msleep(philos->data->time_to_die);
	while (1)
	{
		if (is_someone_dead(tmp))
			return (NULL);
		if (tmp->data->num_of_times_each_philo_must_eat != 0)
		{
			if (did_everyone_eat_min_times(tmp))
				return (NULL);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
