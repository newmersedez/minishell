/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittenb <mwittenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:56:46 by mwittenb          #+#    #+#             */
/*   Updated: 2022/02/25 17:56:55 by mwittenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_wstr(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

char	*path_join(char *s1, char *s2)
{
	char 	*path;

	if (s1[ft_strlen(s1) - 1] != '/')
	{
		path = ft_strjoin(s1, "/");
		return (ft_strjoin(path, s2));
	}
	path = ft_strjoin(s1, s2);
	return (path);
}
