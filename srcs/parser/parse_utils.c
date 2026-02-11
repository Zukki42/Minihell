/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:29:33 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/29 15:29:33 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir_token(t_token *tok)
{
	if (!tok)
		return (0);
	if (tok->type == T_REDIR_IN || tok->type == T_REDIR_OUT
		|| tok->type == T_REDIR_APPEND || tok->type == T_REDIR_HEREDOC)
		return (1);
	return (0);
}

int	argv_size(char **argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	return (i);
}
