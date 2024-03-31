/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:42:51 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/31 10:21:20 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo_info	*init_first_philo_info(t_data *data)
{
	t_philo_info	*philo;

	philo = malloc(sizeof(t_philo_info));
	if (check_error(philo == NULL, MALLOC, NONE) == true)
		return (NULL);
	philo->name = 1;
	philo->prev = philo;
	philo->next = philo;
	philo->data = data;
	data->dead_flag = 0;
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&philo->updated_time_key, NULL);
	pthread_mutex_init(&data->dead_flag_key, NULL);
	philo->num_of_times_of_eating = 0;
	return (philo);
}

t_philo_info	*init_philos_info(t_philo_info *philos, t_data *data, int index)
{
	t_philo_info	*last_philo;
	t_philo_info	*new_philo;

	new_philo = malloc(sizeof(t_philo_info));
	if (check_error(new_philo == NULL, MALLOC, NONE) == true)
		return (NULL);
	last_philo = philos->prev;
	last_philo->next = new_philo;
	new_philo->prev = last_philo;
	philos->prev = new_philo;
	new_philo->next = philos;
	new_philo->name = index;
	new_philo->data = data;
	pthread_mutex_init(&new_philo->fork, NULL);
	pthread_mutex_init(&new_philo->updated_time_key, NULL);
	new_philo->num_of_times_of_eating = 0;
	return (philos);
}

t_philo_info	*init_philos_list(t_data *data)
{
	int				i;
	t_philo_info	*philos;

	philos = init_first_philo_info(data);
	if (philos == NULL)
		return (NULL);
	i = 2;
	while (i <= data->num_of_philos)
	{
		if (init_philos_info(philos, data, i) == NULL)
		{
			free_all(philos);
			return (NULL);
		}
		i++;
	}
	return (philos);
}
