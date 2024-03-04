#include "minitalk_bonus.h"

void	signal_handler(int flag, siginfo_t *info, void *ptr)
{
	(void)info;
	(void)ptr;
	if (flag == SIGUSR1)
		sig_flag = 0;
	else
		sig_flag = 1;
	kill(info->si_pid, SIGUSR1);
}

void	set(t_info *bit_info, struct sigaction *sa1, struct sigaction *sa2)
{
	bit_info->bits = 0;
	bit_info->bits_count = 0;
	bit_info->char_weight = 0;
	bit_info->char_index = 0;
	sigemptyset(&sa1->sa_mask);
	sigemptyset(&sa2->sa_mask);
	sigaddset(&sa1->sa_mask, SIGUSR2);
	sigaddset(&sa2->sa_mask, SIGUSR1);
	sa1->sa_flags = SA_SIGINFO | SA_RESTART;
	sa2->sa_flags = SA_SIGINFO | SA_RESTART;
	sa1->sa_sigaction = signal_handler;
	sa2->sa_sigaction = signal_handler;
	error_check(sigaction(SIGUSR1, sa1, NULL) < 0);
	error_check(sigaction(SIGUSR2, sa2, NULL) < 0);
}
