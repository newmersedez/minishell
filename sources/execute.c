/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittenb <mwittenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:54:00 by mwittenb          #+#    #+#             */
/*   Updated: 2022/02/25 18:06:43 by mwittenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_commands(char **commands)
{
	int		i;
	int		ret;
	char	**command;

	i = -1;
	ret = 0;
	while (commands[++i])
	{
		command = ft_split(commands[i], ' ');
		if (!command)
			return -1;
		ret = exec_command(command);
		free_wstr(command);
		if (ret == -1)
			break ;
	}
	return (ret);
}

int	is_builtins(char **command)
{
	if (!ft_strncmp(command[0], "exit", 4))
		return (-1);
	else if (!ft_strncmp(command[0], "echo", 4))
		return (1);
	else if (!ft_strncmp(command[0], "cd", 2))
		return (1);
	else if (!ft_strncmp(command[0], "pwd", 3))
		return (pwd(1));
	else if (!ft_strncmp(command[0], "export", 6))
		return (1);
	else if (!ft_strncmp(command[0], "unset", 3))
		return (1);
	else if (!ft_strncmp(command[0], "env", 3))
		return (print_env());
	return (0);
}

int	exec_command(char **command)
{
	int	builtin;

	builtin = is_builtins(command);
	if (builtin == 1)
		printf("COOL\n");
	else if (builtin == -1)
		return (builtin);
	else if (!check_bins(command))
		printf("Error: Command not found: %s\n", command[0]);
	return (0);
}



int	is_exec(char *bin_path, char **command)
{
	int			answer;
	struct stat	f;

	(void)command;
	answer = 0;
	if (lstat(bin_path, &f) != -1)
	{
		if (f.st_mode & S_IFDIR)
			printf("Error: it is a directory\n");
		else if (f.st_mode & S_IXUSR && f.st_mode & S_IRUSR)
			answer = 1; // run command
		else
			printf("Error: Permission denied\n");
	}
	free(bin_path);
	bin_path = NULL;
	return (answer);
}
