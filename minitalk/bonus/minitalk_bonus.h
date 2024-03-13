/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:29:31 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/12 12:43:30 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

# define ARG 1
# define PID 2
# define MALLOC 3
# define KILL 4
# define SIGACTION 5
# define WRITE 6

# define TRUE 1
# define FALSE 0

volatile sig_atomic_t	g_flag_server;

typedef struct s_info {
	int		bits;
	char	*str;
	int		bits_count;
	int		char_weight;
	int		char_index;
}	t_info;

void	arg_check(int argc, char *argv[]);
void	error_check(bool is_error, int flag);
bool	ft_isdigit_all(char *pid);
void	set(t_info *bit_info, struct sigaction *sa);
void	get_char_weight(t_info *bit_info);
void	update_bits(t_info *bit_info);
void	ready_for_next_bits(t_info *bit_info);

#endif
