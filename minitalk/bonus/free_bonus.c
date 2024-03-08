/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:29:24 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/08 11:23:12 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	free_all(struct sigaction *sa1, struct sigaction *sa2, t_info *bit_info)
{
	free(sa1);
	free(sa2);
	free(bit_info);
}
