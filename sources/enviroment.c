#include "minishell.h"

static int env_length(char **envp)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (envp[i++])
		count++;
	return (count);
}

void	init_env(int argc, char **argv, char **envp)
{
	int i;

	(void)argc;
	(void)argv;
	enviroment = (char **)malloc(sizeof(char *) * (env_length(envp) + 1));
	if (!enviroment)
		return ;
	i = -1;
	while (envp[++i])
	{
		enviroment[i] = ft_strdup(envp[i]);
		if (!enviroment[i])
		{
			// free_env
			return ;
		}
	}
	enviroment[i] = NULL;
}
