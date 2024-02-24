#include "push_swap.h"

void	arg_init(t_arg *arg, int argc, char **argv)
{
	arg->argc = argc;
	arg->argv = argv;
}

bool	is_int(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == '-' || argv[1][i] == '+')
				return (ft_isdigit(argv[1][i + 1]));
			if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' ')
				return (false);
			i++;
		}
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (argv[i][j] == '-' || argv[i][j] == '+')
					return (ft_isdigit(argv[i][j + 1]));
				if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
					return (false);
				j++;
			}
			i++;
		}
	}
	return (true);
}

bool	is_int_max(int argc, char **argv)
{
	int		i;
	char	**strs;
	int		flag;

	flag = 0;
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		i = 0;
		while (strs[i])
		{
			if (INT_MAX < ft_atoi(strs[i]) || INT_MIN > ft_atoi(strs[i]))
				flag = 1;
			i++;
		}
		i = 0;
		while (strs[i])
			free(strs[i++]);
		free(strs);
		if (flag == 1)
			return (false);
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			if (INT_MAX < ft_atoi(argv[i]) || INT_MIN > ft_atoi(argv[i]))
				return (false);
			i++;
		}
	}
	return (true);
}

bool	is_dupe(int argc, char **argv)
{
	char	**strs;
	int		i;
	int		j;
	int		flag;

	flag = 0;
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		i = 0;
		while (strs[i + 1])
		{
			j = i + 1;
			while (strs[j])
			{
				if (ft_strncmp(strs[i], strs[j], ft_strlen(strs[i]) + 1) == 0)
					flag = 1;
				j++;
			}
			i++;
		}
		i = 0;
		while (strs[i])
			free(strs[i++]);
		free(strs);
		if (flag == 1)
			return (false);
	}
	else
	{
		i = 1;
		while (argv[i + 1])
		{
			j = i + 1;
			while (argv[j])
			{
				if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i]) + 1) == 0)
					return (false);
				j++;
			}
			i++;
		}
	}
	return (true);
}

bool	check_double_quote(int argc, char **argv)
{
	int		i;
	int		j;
	char	**strs;
	int		flag;

	flag = 0;
	i = 1;
	if (argc > 2)
	{
		while (argv[i])
		{
			strs = ft_split(argv[i], ' ');
			if (strs[1] != '\0')
				flag = 1;
			j = 0;
			while (strs[j])
				free(strs[j++]);
			free(strs);
			i++;
		}
		if (flag == 1)
			return (false);
	}
	return (true);
}

t_arg	*arg_check(int argc, char **argv)
{
	t_arg	*arg;

//--------arg check--------------
//	no arg->invaid arg, too many args->time out?.
	if (argc < 2)
		exit(0);
	check_error(is_int(argc, argv) == false);
	check_error(is_int_max(argc, argv) == false);
	check_error(is_dupe(argc, argv) == false);
	check_error(check_double_quote(argc, argv) == false);
//	already sorted
	arg = malloc(sizeof(t_arg));
	arg_init(arg, argc, argv);
	return (arg);
}
