#ifndef MINISHELL_H
#define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

char		**enviroment;


void		init_env(int argc, char **argv, char **envp);

// Utils
void		free_wstr(char **arr);

#endif
