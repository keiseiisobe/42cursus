/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:47:15 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/16 14:48:07 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo_info *philos)
{
	t_philo_info	*tmp;

	tmp = philos;
	while (tmp->next != philos)
	{
		free(tmp);
		tmp = tmp->next;
	}
	free(tmp);
}
