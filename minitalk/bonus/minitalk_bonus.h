/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:29:31 by kisobe            #+#    #+#             */
/*   Updated: 2024/03/08 11:31:26 by kisobe           ###   ########.fr       */
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
void	set(t_info *bit_info, struct sigaction *sa1, struct sigaction *sa2);
void	get_char_weight(t_info *bit_info, int bit_flag);
void	update_bits(t_info *bit_info);
void	ready_for_next_bits(t_info *bit_info);
void	free_all(struct sigaction *sa1, struct sigaction *sa2,
			t_info *bit_info);

#endif
