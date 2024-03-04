#include "minitalk_bonus.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q client_bonus");
}

void	send_bits(int pid, char *str)
{
	int	bit_shift;
	int	bit;
	int	i;

	i = 0;
	while (str[i])
	{
		bit_shift = 7;
		while (bit_shift >= 0)
		{
			bit = (str[i] >> bit_shift) & 1;
			if (bit == 0)
				error_check(kill(pid, SIGUSR1) < 0);
			else
				error_check(kill(pid, SIGUSR2) < 0);
			usleep(1000);
			bit_shift--;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	(void)argc;
	error_check(argc != 3);
// handle for minus PID argument !!!
// handle when pid is not accessable ???
	pid = atoi(argv[1]);// you have to replace atoi to ft_atoi
//---test: acknowledge sending back from server (bonus)---
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = SIG_IGN;
	sigaction(SIGUSR1, &sa, NULL);
	send_bits(pid, argv[2]);
	return(0);
}
