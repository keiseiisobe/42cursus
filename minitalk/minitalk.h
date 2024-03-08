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
# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

# define ARG 1
# define PID 2
# define MALLOC 3
# define KILL 4
# define SIGACTION 5
# define WRITE 6

volatile sig_atomic_t	g_flag;

typedef struct s_info {
	int	bits;
	int	bits_count;
}	t_info;

void	error_check(bool is_error, int flag);

#endif
