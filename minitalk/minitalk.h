# ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

volatile sig_atomic_t	sig_flag;

typedef struct s_info {
	int	bits;
	int	bits_count;
}	t_info;

void	error_check(bool is_error);

#endif
