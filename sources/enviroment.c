/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittenb <mwittenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:54:36 by mwittenb          #+#    #+#             */
/*   Updated: 2022/02/25 18:05:50 by mwittenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_env(void)
{
	int	i;

	i = -1;
	while (data.enviroment[++i])
		printf("%s\n", data.enviroment[i]);
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
	data.enviroment = (char **)malloc(sizeof(char *) * (env_length(envp) + 1));
	if (!data.enviroment)
		return ;
	i = -1;
	while (envp[++i])
	{
		data.enviroment[i] = ft_strdup(envp[i]);
		if (!data.enviroment[i])
		{
			// free_env
			return ;
		}
	}
	data.enviroment[i] = NULL;
}

char	*get_env_var(char *var)
{
	int		i;
	char	*temp;

	i = -1;
	temp = ft_strjoin(var, "=");
	while (data.enviroment[++i])
	{
		if (!ft_strncmp(data.enviroment[i], temp, ft_strlen(temp)))
		{
			free(temp);
			return (ft_strchr(data.enviroment[i], '=') + 1);
		}
	}
	free(temp);
	return (NULL);
}
