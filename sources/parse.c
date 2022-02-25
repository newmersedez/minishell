/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:39:04 by lorphan           #+#    #+#             */
/*   Updated: 2022/02/25 19:07:57 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int parse_commandline(char *command_line)
{
    data.commands = ft_split(command_line, ';');
    if (!data.commands)
        return (-1);

    return (0);    
}
