/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:28:46 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/08 11:16:27 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_check(bool is_error, int flag)
{
	if (is_error == true)
	{
		if (flag == ARG)
			ft_printf("Invalid argment !!!\n");
		else if (flag == PID)
			ft_printf("Invalid process id !!!\n");
		else if (flag == MALLOC)
			ft_printf("Memory allocation failed !!!\n");
		else if (flag == KILL)
			ft_printf("Kill function failed !!!\n");
		else if (flag == SIGACTION)
			ft_printf("Sigaction function failed !!!\n");
		else if (flag == WRITE)
			ft_printf("Write function failed !!!\n");
		exit(1);
	}
}
