/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:03:44 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/17 12:34:38 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q philo");
}

int	main(int argc, char *argv[])
{
	int				i;
	t_philo_info	*tmp;
	t_args			args;
	t_philo_info	philo;
	t_philo_info	*philos;
	pthread_t		monitor;

	if (handle_args(&args, argc, argv) == RETURN_FAILURE)
		return (RETURN_FAILURE);
	philos = init_philos_list(&philo, &args);
	if (philos == NULL)
		return (RETURN_FAILURE);
	pthread_create(&monitor, NULL, monitor_the_end_of_simulation, philos);
	i = 1;
	tmp = philos;
	while (i <= args.num_of_philos)
	{
		pthread_create(&tmp->thread_id, NULL, philo_do, tmp);
		tmp = tmp->next;
		i++;
	}
	// pthread_detach is better ??? it may be useful for monitoring thread.
	monitor_the_end_of_simulation(philos);
	pthread_join_all(philos, args.num_of_philos, monitor);
	free_all(philos);
	return (RETURN_SUCCESS);
}

/*
//------print for test----------
	t_philo_info	*tmp;

	tmp = philos;
	while (tmp->next != philos)
	{
		printf("name is %d, address is %p, prev is %p, next is %p, fork is %p\n", tmp->name, tmp, tmp->prev, tmp->next, &tmp->fork);
		tmp = tmp->next;
	}
	printf("name is %d, address is %p, prev is %p, next is %p, fork is %p\n", tmp->name, tmp, tmp->prev, tmp->next, &tmp->fork);
//---------------------------
*/
