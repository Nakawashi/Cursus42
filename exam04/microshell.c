#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void	print_err(char *str, int err)
{
	int	i;

	i = 0;
	while(str[i])
		++i;
	write(2, str, i);
	if (err == 1)
		exit(1);
}

void	ft_perror(char *str, char *cmd)
{
	print_err(str, 0);
	print_err(cmd, 0);
	print_err("\n", 0);
}

void	ft_cd(char **cmd)
{
	if (!cmd[1]) return print_err("error: cd: bad arguments\n", 0);
	if (chdir(cmd[1]) == -1) return ft_perror("error: cd: cannot change directory to ", cmd[1]);
}

void	exec_cmd(char **cmd, char *path, char **env, int last_cmd)
{
	int	fd[2];
	int	pid;

	if (!cmd[0]) return ;
	if (!strcmp(cmd[0], "cd")) return ft_cd(cmd);
	if (pipe(fd) == -1) print_err("error: fatal\n", 1);
	if ((pid = fork()) == -1) print_err("error: fatal\n", 1);

	if (pid)
	{
		if (close(fd[1]) == -1) print_err("error: fatal\n", 1);
		if (dup2(fd[0], 0) == -1) print_err("error: fatal\n", 1);
		if (close(fd[0]) == -1) print_err("error: fatal\n", 1);
		if (waitpid(pid, NULL, 0) == -1) print_err("error: fatal\n", 1);
	}
	else
	{
		if (close(fd[0]) == -1) print_err("error: fatal\n", 1);
		if (!last_cmd)
			if (dup2(fd[1], 1) == -1) print_err("error: fatal\n", 1);
		execve(path, cmd, env);
		ft_perror("error: cannot execute ", cmd[0]);
		exit(1);
	}
}

int	main(int argc, char **argv, char **env)
{
	int cmd = 1;

	for(int i = 1; i < argc; ++i)
	{
		if (!strcmp(argv[i], ";"))
		{
			argv[i] = NULL;
			exec_cmd(&argv[cmd], argv[cmd], env, 1);
			cmd = i + 1;
		}
		else if (!strcmp(argv[i], "|"))
		{
			argv[i] = NULL;
			exec_cmd(&argv[cmd], argv[cmd], env, 0);
			cmd = i + 1;
		}
	}
	exec_cmd(&argv[cmd], argv[cmd], env, 1);
	return 0;
}
