/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:01:50 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/17 12:26:23 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_forks(t_philo_info *philo)
{
	struct timeval	tp;

	pthread_mutex_lock(&philo->fork);
	gettimeofday(&tp, NULL);
	pthread_mutex_lock(&philo->print);
	if (wrapper_printf("%d %d has taken a fork\n", tp.tv_usec / 1000, philo->name, philo->dead_flag) == CANCEL)
	{
		pthread_mutex_unlock(&philo->print);
		return (CANCEL);
	}
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(&philo->next->fork);
	gettimeofday(&tp, NULL);
	pthread_mutex_lock(&philo->print);
	if (wrapper_printf("%d %d has taken a fork\n", tp.tv_usec / 1000, philo->name, philo->dead_flag) == CANCEL)
	{
		pthread_mutex_unlock(&philo->print);
		return (CANCEL);
	}
	pthread_mutex_unlock(&philo->print);
	return (CONTINUE);
}

void	update_time_to_start_eating(t_philo_info *philo)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	philo->time_to_start_eating = tp.tv_usec;
}

int	ft_eat(t_philo_info *philo)
{
	struct timeval	tp;

	update_time_to_start_eating(philo);
	// does it handle for the beggining of simulation ???
	gettimeofday(&tp, NULL);
	pthread_mutex_lock(&philo->print);
	if (wrapper_printf("%d %d is eating\n", tp.tv_usec / 1000, philo->name, philo->dead_flag) == CANCEL)
	{
		pthread_mutex_unlock(&philo->print);
		return (CANCEL);
	}
	pthread_mutex_unlock(&philo->print);
	usleep(philo->args->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	philo->num_of_times_of_eating++;
	return (CONTINUE);
}

int	ft_sleep(t_philo_info *philo)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	pthread_mutex_lock(&philo->print);
	if (wrapper_printf("%d %d is sleeping\n", tp.tv_usec / 1000, philo->name, philo->dead_flag) == CANCEL)
	{
		pthread_mutex_unlock(&philo->print);
		return (CANCEL);
	}
	pthread_mutex_unlock(&philo->print);
	usleep(philo->args->time_to_sleep * 1000);
	return (CONTINUE);
}

int	ft_think(t_philo_info *philo)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	pthread_mutex_lock(&philo->print);
	if (wrapper_printf("%d %d is thinking\n", tp.tv_usec / 1000, philo->name, philo->dead_flag) == CANCEL)
	{
		pthread_mutex_unlock(&philo->print);
		return (CANCEL);
	}
	pthread_mutex_unlock(&philo->print);
	return (CONTINUE);
}


void	check_if_odd_philo(t_philo_info *philo)
{
	if (philo->name % 2 == 0)
		usleep(200);
}

void	*philo_do(void *philo_info)
{
	t_philo_info	*philo;
	struct timeval	tp;

	philo = (t_philo_info *)philo_info;
	gettimeofday(&tp, NULL);
	philo->time_to_start_eating = tp.tv_usec;
	check_if_odd_philo(philo);
	while (1) // is there race condition ???
	{
		if (ft_take_forks(philo) == CANCEL)
			break;
		if (ft_eat(philo) == CANCEL)
			break;
		if (ft_sleep(philo) == CANCEL)
			break;
		if (ft_think(philo) == CANCEL)
			break;
	}
	return (NULL);
}
