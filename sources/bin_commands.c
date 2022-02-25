#include "minishell.h"

int check_bins(char **command)
{
	int		i;
	char	*bin_path;
	char	**paths;

	paths = ft_split(get_env_var("PATH"), ':');
	i = -1;
	while (paths && paths[++i])
	{
		bin_path = path_join(paths[i], command[0]);
		if (!access(bin_path, X_OK))
			break ;
		free(bin_path);
		bin_path = NULL;
	}
	if (bin_path)
		return (is_exec(bin_path, command));
	free_wstr(paths);
	return (0);
}
