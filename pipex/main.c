#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <sys/wait.h>

char	**ft_split(char const *s, char c);

int	main(void)
{
	char	*line;
	char	**operations;
	int		fds[2];
	pid_t	child1_pid;
	int		child1_status;
	pid_t	child2_pid;
	int		child2_status;
	char	*argv0[2];
	char	*argv1[2];
	int		i = 0;
	char	*error_msg;

	line = readline("bash$ ");
	operations = ft_split(line, ' ');

	pipe(fds);
	child1_pid = fork();
	if (child1_pid < 0)
		return (1);
	else if (child1_pid) // parent
	{
		child2_pid = fork();
		if (child2_pid < 0)
			exit(1);
		else if (!child2_pid)// child2
		{
			waitpid(child1_pid, &child1_status, 0);
//			printf("child1_status is %d\n", WIFSIGNALED(child1_status));
//			printf("child1_signal is %d\n", WTERMSIG(child1_status));
			if (WIFEXITED(child1_status))
				printf("child1 exited\n");
			argv1[0] = operations[2];
			argv1[1] = NULL;
			dup2(fds[0], STDIN_FILENO);
			close(fds[0]);
			close(fds[1]);
			execve("/usr/bin/more", argv1, NULL);
		}
		else
		{
			close(fds[0]);
			close(fds[1]);
			waitpid(child2_pid, &child2_status, 0);
		}
		return (0);
	}
	else if (!child1_pid)// child1
	{
		argv0[0] = operations[0];
		argv0[1] = NULL;
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		close(fds[1]);
		execve("/bin/ls", argv0, NULL);
	}
	free(line);
	while (operations[i])
		free(operations[i++]);
	free(operations);

	perror(error_msg);
}
