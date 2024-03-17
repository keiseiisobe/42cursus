/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:52:19 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/17 12:45:08 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	change_all_dead_flags(t_philo_info *philos)
{
	t_philo_info	*tmp;

	tmp = philos;
	while (tmp->next != philos)
	{
		tmp->dead_flag = 1;
		tmp = tmp->next;
	}
	tmp->dead_flag = 1;
}

bool	is_someone_dead(t_philo_info *philos, t_philo_info *tmp)
{
	struct timeval	current_time;
	suseconds_t		death_time;

	gettimeofday(&current_time, NULL);
	death_time = tmp->time_to_start_eating + tmp->args->time_to_die * 1000;
	if (current_time.tv_usec >= death_time)
	{
		pthread_mutex_lock(&tmp->print);
		printf("%d %d died\n", current_time.tv_usec / 1000, tmp->name);
		change_all_dead_flags(philos);
		pthread_mutex_unlock(&tmp->print);
		return (true);
	}
	return (false);
}

bool	did_everyone_eat_min_times(t_philo_info *tmp)
{
	static int	num_of_philos_achieved = 0;

	if (tmp->num_of_times_of_eating == tmp->args->num_of_times_each_philo_must_eat)
		num_of_philos_achieved++;
	else
		num_of_philos_achieved = 0;
	if (num_of_philos_achieved == tmp->args->num_of_philos)
	{
		pthread_mutex_lock(&tmp->print);
		while (tmp->name != 1)
			tmp = tmp->next;
		change_all_dead_flags(tmp);
		pthread_mutex_unlock(&tmp->print);
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
	usleep(200);
	while (1)
	{
		if (is_someone_dead(philos, tmp))
			return (NULL);
		if (did_everyone_eat_min_times(tmp))
			return (NULL);
		tmp = tmp->next;
	}
	return (NULL);
}
