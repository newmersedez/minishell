/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwittenb <mwittenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:54:20 by mwittenb          #+#    #+#             */
/*   Updated: 2022/02/25 17:56:39 by mwittenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
