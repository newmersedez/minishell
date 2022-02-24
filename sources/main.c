#include "../includes/minishell.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	count_words(char *command)
{
	size_t	i;
	int		count;

	if (!command)
		return (0);
	i = 0;
	count = 0;
	while (command[i])
	{
		while (command[i] && ft_isspace(command[i]))
			i++;
		if (command[i] && !ft_isspace(command[i]))
			count++;
		while (command[i] && !ft_isspace(command[i]))
			i++;
	}
	return (count);
}

int	count_word_length(char *command)
{
	int	i;

	if (!command)
		return (0);
	i = 0;
	while (command[i] && !ft_isspace(command[i]))
		i++;
	return (i);
}

char	**split_command(char *command)
{
	int		i;
	int		j;
	int		count;
	char	*splitted_command;

	if (!command)
		return (NULL);
	i = 0;
	while (command[i])
	{
		
		i++;
	}
}

int	exec_commands(char **commands)
{
	int		i;
	int		j;
	int		ret = 0;
	char	**command;

	i = 0;
	while (commands[i])
	{
		command = split_command(commands[i]);
		//ret = exec_command(command);
		//free_string_array(command);
		i++;
	}
	return (ret);
}

int main(int argc, char **argv, char **envp)
{
	int		ret;
	char	*input_str;
	char	**commands;

	init_env(argc, argv, envp);
	ret = 0;
	while (1)
	{
		input_str = readline("😎 minishell$> ");
		printf("%s\n", input_str);
		// if (!check_input(input_str))
		// {
		// 	free(input_str);
		// 	continue ;
		// }
		commands = ft_split(input_str, ';');
		free(input_str);
		ret = exec_commands(commands);
		free_wstr(commands);
		// if (ret == -1)
		// 	break ;
	}
	free_wstr(enviroment);
	return (0);
}
