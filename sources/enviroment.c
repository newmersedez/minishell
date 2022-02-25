#include "minishell.h"

int	print_env(void)
{
	int	i;

	i = -1;
	while (enviroment[++i])
		printf("%s\n", enviroment[i]);
	return (1);
}

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

char	*get_env_var(char *var)
{
	int		i;
	char	*temp;

	i = -1;
	temp = ft_strjoin(var, "=");
	while (enviroment[++i])
	{
		if (!ft_strncmp(enviroment[i], temp, ft_strlen(temp)))
		{
			free(temp);
			return (ft_strchr(enviroment[i], '=') + 1);
		}
	}
	free(temp);
	return (NULL);
}
