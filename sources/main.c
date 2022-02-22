#include "../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
	// char	*input_str;
	(void)argc;
	(void)argv;
	(void)envp;

	rl_replace_line("s", 1);
}
