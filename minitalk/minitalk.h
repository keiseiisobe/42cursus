/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:28:53 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/08 11:31:05 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

volatile sig_atomic_t	g_flag;

typedef struct s_info {
	int	bits;
	int	bits_count;
}	t_info;

void	error_check(bool is_error);

#endif
