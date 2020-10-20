#include "minishell.h"
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_exec(char **full)
{
	pid_t	pid, wpid;
	int		status;


	pid = fork();
	char *args[] = {"ls", 0};
	if (pid == 0)
		execve("/bin/ls", args, NULL);
	else if (pid < 0)
		ft_error(1);
	wait(&pid);
}

void	ft_minishell(void)
{
	int 	i;
	char	*cmd;
	char	**full;

	i = 1;
	while (1)
	{
		signal(SIGINT, ft_signals);
		signal(SIGQUIT, ft_signals);
		char *str[4];
		str[0] = "ls";
		str[1] = "-aF";
		str[2] = "/";
		str[3] = 0;
		write(1, "\033[0;36m Σ>―(〃°ω°〃)♡→ \033[0;35m", 43);
		write(1, getcwd(NULL, 0), ft_strlen(getcwd(NULL, 0)));
		write(1, ">\033[0m ", 7);
		get_next_line(0, &cmd);
		full = ft_split(cmd, ' ');
		ft_exec(full);
	}
}
