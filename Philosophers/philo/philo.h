/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:40:49 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/13 16:38:32 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct s_args {
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_args;

typedef struct s_philo {
	int				name;
	pthread_t		*thread;
	t_args			*args;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
}	t_philo;

bool	args_are_invalid(int argc, char *argv[]);

bool	check_error(bool is_error, int flag);

void	free_all(t_philo *philo, pthread_mutex_t *mutex);

void	init_args(t_args *args, int argc, char *argv[]);
void	init_philos(t_philo *philos, t_args *args, pthread_mutex_t *mutex);
void	pthread_mutex_init_all(pthread_mutex_t *mutex);

void	pthread_join_all(t_philo *philos, int num_of_philos);

void	ft_take_a_right_fork();
void	ft_take_a_left_fork();
void	ft_eat();
void	ft_sleep();
void	ft_think();
void	*philo_do(void *info);

# endif
