#include "push_swap.h"

void  arg_init(t_arg *arg, int argc, char *argv[])
{
  arg->argc = argc;
  arg->argv[] = argv[];
}

t_arg *arg_check(int argc, char *argv[])
{
  t_arg *arg;

  arg = malloc(sizeof(t_arg));
  arg_init(arg, argc, argv[]);
//--------arg check--------------
//	no arg->invaid arg, too many args->time out?.
//
//	already sorted, arg aren't intgers, bigger than int, duplicate, agrs with "".
//	./push_swap "2 0" 1 3   this kind of arg will cause Error(case 1),
//	but ./push_swap "2" 0 1 3 will be permitted.
//	and ./push_swap "2 0 1 3" will be permitted.
//	if (ft_split[i][1] != NULL && argv[i + 1] != NULL)
//		invalid arg (case 1)
}
