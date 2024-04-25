/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:03:44 by kisobe            #+#    #+#             */
/*   Updated: 2024/04/16 10:40:06 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
__attribute__((destructor))
static void destructor() {
    system("leaks -q philo");
}
*/
int	main(int argc, char *argv[])
{
	int				i;
	t_data			data;
	t_philo_info	*philos;
	pthread_t		monitor;

	if (handle_args(&data, argc, argv) == RETURN_FAILURE)
		return (RETURN_FAILURE);
	philos = init_philos_list(&data);
	if (philos == NULL)
		return (RETURN_FAILURE);
	if (check_error(pthread_create(&monitor, NULL,
				monitor_the_end_of_simulation, philos) != 0, PTHREAD, NONE))
		return (RETURN_FAILURE);
	i = 1;
	data.start_time = get_current_time(0);
	while (i++ <= data.num_of_philos)
	{
		if (check_error(pthread_create(&philos->thread_id, NULL,
					philo_do, philos) != 0, PTHREAD, NONE))
			return (RETURN_FAILURE);
		philos = philos->next;
	}
	pthread_join_all(philos, data.num_of_philos, monitor);
	return (RETURN_SUCCESS);
}
