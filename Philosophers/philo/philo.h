/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:40:49 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/17 12:42:30 by kisobe           ###   ########.fr       */
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
#include <sys/time.h>
#include <limits.h>

# define RETURN_SUCCESS 0
# define RETURN_FAILURE 1

# define ARG 0
# define MALLOC 1
# define ARGC 2
# define DIGIT 3
# define MINUS 4
# define TOO_MANY_PHILOS 5
# define TIME_MIN 6
# define MAX 7
# define NONE 8
# define OVER_INT_MAX -1

# define TRUE 1
# define FALSE 0

# define CONTINUE 0
# define CANCEL 1

typedef struct s_args {
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_each_philo_must_eat;
}	t_args;

typedef struct s_philo_info {
	int					name;
	struct s_philo_info	*prev;
	struct s_philo_info	*next;
	pthread_t			thread_id;
	t_args				*args;
	suseconds_t			time_to_start_eating;
	int					dead_flag;
	pthread_mutex_t		fork;
	pthread_mutex_t		print;
	int					num_of_times_of_eating;
}	t_philo_info;

bool			args_are_invalid(int argc, char *argv[]);
void			init_args(t_args *args, int argc, char *argv[]);
int				handle_args(t_args *args, int argc, char *argv[]);

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
bool			args_are_not_digit(char **argv);
bool			is_less_than(int num, int argc, char **argv);
bool			is_more_than(long num, int argc, char **argv);

bool			check_error(bool is_error, int error_type, int error_msg);

t_philo_info	*init_philos_list(t_philo_info *philo, t_args *args);

void			*philo_do(void *info);
int				wrapper_printf(char *str, suseconds_t timestamp_in_ms, int philo_name, int dead_flag);
void			*monitor_the_end_of_simulation(void *arg);
void			pthread_join_all(t_philo_info *philos, int num_of_philos, pthread_t monitor);

void			free_all(t_philo_info *philos);


# endif
