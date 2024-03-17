/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:42:51 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/17 12:07:33 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo_info	*init_first_philo_info(t_philo_info *philo, t_args *args)
{
	philo = malloc(sizeof(t_philo_info));
	if (check_error(philo == NULL, MALLOC, NONE) == true)
		return (NULL);
	philo->name = 1;
	philo->prev = philo;
	philo->next = philo;
	philo->args = args;
	philo->dead_flag = 0;
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->print, NULL);
	philo->num_of_times_of_eating = 0;
	return (philo);
}

t_philo_info	*init_philos_info(t_philo_info *philos, t_args *args, int index)
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
	new_philo->args = args;
	new_philo->dead_flag = 0;
	pthread_mutex_init(&new_philo->fork, NULL);
	new_philo->print = philos->print;
	new_philo->num_of_times_of_eating = 0;
	return (philos);
}

t_philo_info	*init_philos_list(t_philo_info *philo, t_args *args)
{
	int				i;
	t_philo_info	*philos;

	philos = init_first_philo_info(philo, args);
	if (philos == NULL)
		return (NULL);
	i = 2;
	while (i <= args->num_of_philos)
	{
		if (init_philos_info(philos, args, i) == NULL)
		{
			free_all(philos);
			return (NULL);
		}
		i++;
	}
	return (philos);
}
