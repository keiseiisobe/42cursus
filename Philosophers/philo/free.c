/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:22:35 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/31 17:33:56 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo_info *philos)
{
	t_philo_info	*tmp;
	t_philo_info	*tmp_next;

	tmp = philos;
	while (tmp->next != philos)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	free(tmp);
}
