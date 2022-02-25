#include "minishell.h"

int	pwd(int	flag)
{
	char	*path;
	path = getcwd(NULL, 0);
	if (!path)
		return (0);
	ft_putstr_fd(path, 1);
	if (flag)
		ft_putchar_fd('\n', 1);
	return (1);
}
