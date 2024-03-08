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
# include <string.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

volatile sig_atomic_t	g_flag_server;

typedef struct s_info {
	int		bits;
	char	*str;
	int		bits_count;
	int		char_weight;
	int		char_index;
}	t_info;

void	set(t_info *bit_info, struct sigaction *sa1, struct sigaction *sa2);
void	get_char_weight(t_info *bit_info, int bit_flag);
void	update_bits(t_info *bit_info);
void	ready_for_next_bits(t_info *bit_info);
void	error_check(bool is_error);
void	free_all(struct sigaction *sa1, struct sigaction *sa2,
			t_info *bit_info);

#endif
