#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	int	bit;
	int	bit_count;

	error_check(argc != 3);
	pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		bit_count = 7;
		while (bit_count >= 0)
		{
			bit = (argv[2][i] >> bit_count) & 1;
			if (bit == 0)
				error_check(kill(pid, SIGUSR1) < 0);
			else
				error_check(kill(pid, SIGUSR2) < 0);
			usleep(1000);
			bit_count--;
		}
		i++;
	}
}
