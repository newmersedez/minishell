#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	int		ret;
	char	*input_str;

	init_env(argc, argv, envp);
	ret = 0;
	while (1)
	{
		input_str = readline("😎 minishell$> ");
		add_history(input_str);
		parse_commandline(input_str);
		free(input_str);


		// data.commands = ft_split(input_str, ';');
		// free(input_str);
		// ret = exec_commands(data.commands);
		// parse_command(&data);
		// free_wstr(data.commands);
		// if (ret == -1)
		//  	break ;
	}
	free_wstr(data.enviroment);
	return (0);
}
