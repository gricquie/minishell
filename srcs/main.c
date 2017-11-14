#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

char	**split(char *str, char *delim)
{
	char	**res;
	size_t	size;

	if (!str)
		return (NULL);
	res = malloc(sizeof(*res));
	if (!(res[0] = strtok(str, delim)))
		return (res);
	res = realloc(res, sizeof(*res) * 2);
	res[1] = NULL;
	size = 1;
	while ((res[size] = strtok(NULL, delim)))
	{
		size++;
		res = realloc(res, sizeof(*res) * (size + 1));
		res[size] = NULL;
	}
	return (res);
}

char	**get_path(void)
{
	size_t	i;
	char	**path;

	i = 0;
	while (environ[i])
	{
		if (!strncmp(environ[i], "PATH=", 5))
			path = split(environ[i] + 5, ":");
		i++;
	}
	return (path);
}

int		main()
{
	char	**path;
	char	cmd[256];
	char	**cmd_argv;
	size_t	i;
	int		found = 0;

	if (!(path = get_path()))
		return (EXIT_FAILURE);
	cmd[read(1, cmd, sizeof(cmd)) - 1] = '\0';
	cmd_argv = split(cmd, " ");
	i = 0;
	if (cmd_argv[0][0] == '.' && !access(cmd_argv[0], F_OK))
	{
		int status;
		found = 1;
		pid_t	pid = fork();
		if (!pid)
			execv(cmd_argv[0], cmd_argv);
		wait(&status);
	}
	while (path[i])
	{
		char	cat[1024];

		strcpy(cat, path[i]);
		strcat(cat, "/");
		strcat(cat, cmd_argv[0]);
		if (cmd_argv[0][0] != '.' && !access(cat, F_OK))
		{
			int status;
			found = 1;
			pid_t	pid = fork();
			if (!pid)
				execv(cat, cmd_argv);
			wait(&status);
			break;
		}
		i++;
	}
	if (!found)
		puts("command not found");
	free(path);
}
