#include "minitalk_bonus.h"

void	free_all(struct sigaction *sa1, struct sigaction *sa2, t_info *bit_info)
{
	free(sa1);
	free(sa2);
	free(bit_info);
}
