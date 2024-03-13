/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:01:50 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/13 16:48:05 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_a_right_fork()
{

}

void	ft_take_a_left_fork()
{

}

void	ft_eat()
{

}

void	ft_sleep()
{

}

void	ft_think()
{

}

void	*philo_do(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	while (1) // is there race condition ???
	{
		// you must lock only the right fork on the "philo[i]".
		// the fork can be the left fork on the "philo[i - 1]".
		ft_take_a_right_fork(); // philo must take a fork by this order.
		// you must lock only the left fork on the "philo[i]".
		// the fork can be the right fork on the "philo[i + 1]".
		ft_take_a_left_fork();
		ft_eat();
		// you must unlock both side fork on the philo[i].
		ft_sleep();
		ft_think();
	}
	return (NULL);
}
