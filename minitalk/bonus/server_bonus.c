#include "minitalk_bonus.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q server_bonus");
}

int	main()
{
	struct sigaction	*sa1;
	struct sigaction	*sa2;
	t_info				*bit_info;

//	notice you have to replace printf to ft_printf.
	printf("PID: %d\n", getpid());
	bit_info = malloc(sizeof(t_info));
	sa1 = malloc(sizeof(struct sigaction));
	sa2 = malloc(sizeof(struct sigaction));
	error_check(bit_info == NULL || sa1 == NULL || sa2 == NULL);
	set(bit_info, sa1, sa2);
	while (1)
	{
		pause();
		if (bit_info->char_weight == 0)
			get_char_weight(bit_info, sig_flag);
		bit_info->bits_count++;
		update_bits(bit_info);
		ready_for_next_bits(bit_info);
	}
	free_all(sa1, sa2, bit_info);
}
