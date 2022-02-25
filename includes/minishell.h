#ifndef MINISHELL_H
#define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_mshell
{
	char	**enviroment;
	char	**commands;
} t_mshell;

struct s_mshell	data;

// data.enviroment
void		init_env(int argc, char **argv, char **envp);
char		*get_env_var(char *var);
int			print_env(void);

// Execute
int			exec_commands(char **commands);
int			exec_command(char **command);
int			check_bins(char **command);
int			is_exec(char *bin_path, char **command);

// Parser
int			parse_commandline(char *command_line);

// Utils
void		free_wstr(char **arr);
char		*path_join(char *s1, char *s2);

int			pwd(int flag);

#endif
