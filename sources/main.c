#include "../includes/minishell.h"

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
		// ret = exec_commands(commands);
		free_wstr(commands);
		// if (ret == -1)
		// 	break ;
	}
	free_wstr(enviroment);
	return (0);
}
