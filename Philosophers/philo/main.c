/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:03:44 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/13 16:53:08 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[]) // ./philo [num_of_philos] [time_to_die] [time_to_eat] [time_to_sleep] ([num_of_times_each_philo_must_eat])
{
	int				i;
	t_args			args;
	t_philo			*philos;// "struct philo"s array
	pthread_t		*thread;
	pthread_mutex_t	*mutex;

	if (args_are_invalid(argc, argv) == true);
		return (EXIT_FAILURE);
	init_args(&args, argc, argv);
	// peer model
	mutex = malloc((args.num_of_philos + 1) * sizeof(pthread_mutex_t));
	if (check_error(mutex == NULL) == true)
	{
		free(philos);
		return (EXIT_FAILURE);
	}
	pthread_mutex_init_all(mutex);// how to use in take_a_fork func ???
	philos = malloc((args.num_of_philos + 1) * sizeof(t_philo));
	if (check_error(philos == NULL) == true)
		return (EXIT_FAILURE);
	init_philos(philos, &args, mutex);
	// create all threads first. but monitoring thread is ...?
	i = 0;
	while (i < args.num_of_philos)
	{
		pthread_create(philos[i].thread, NULL, philo_do, &philos[i]);
		i++;
	}
	// pthread_detach is better ??? it may be useful for monitoring thread.
	pthread_join_all(&philos, args.num_of_philos);
	free_all(philos, mutex);
	return (0);
}
