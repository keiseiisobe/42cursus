/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:40:49 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/31 10:23:24 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

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
# define PTHREAD 9
# define OVER_INT_MAX -1

# define TRUE 1
# define FALSE 0

# define CONTINUE 0
# define CANCEL 1

typedef struct s_data {
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	size_t			start_time;
	pthread_mutex_t	write;
	int				dead_flag;
	pthread_mutex_t	dead_flag_key;
}	t_data;

typedef struct s_philo_info {
	int					name;
	struct s_philo_info	*prev;
	struct s_philo_info	*next;
	pthread_t			thread_id;
	t_data				*data;
	size_t				time_to_start_eating;
	pthread_mutex_t		fork;
	pthread_mutex_t		updated_time_key;
	int					num_of_times_of_eating;
}	t_philo_info;

bool			args_are_invalid(int argc, char *argv[]);
void			init_arg_data(t_data *data, int argc, char *argv[]);
int				handle_args(t_data *data, int argc, char *argv[]);

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
bool			args_are_not_digit(char **argv);
bool			is_less_than(int num, int argc, char **argv);
bool			is_more_than(long num, int argc, char **argv);

bool			check_error(bool is_error, int error_type, int error_msg);

t_philo_info	*init_philos_list(t_data *data);

void			*philo_do(void *info);
int				wrapper_printf(char *str, size_t timestamp_in_ms,
					t_philo_info *philo, int dead_flag);

size_t			get_current_time(size_t start_time);
void			ft_msleep(size_t ms);
int				handle_one_philo(t_philo_info *philo);
void			update_time_to_start_eating(t_philo_info *philo);
void			check_if_odd_philo(t_philo_info *philo);

void			*monitor_the_end_of_simulation(void *arg);
void			pthread_join_all(t_philo_info *philos,
					int num_of_philos, pthread_t monitor);

void			free_all(t_philo_info *philos);

#endif
