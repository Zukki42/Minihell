/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:31:07 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/29 15:31:08 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_cmds(t_cmd *cmd)
{
	int		i;
	t_redir	*r;

	while (cmd)
	{
		printf("=== COMMAND ===\n");
		i = 0;
		while (cmd->argv && cmd->argv[i])
		{
			printf(" argv[%d] = %s\n", i, cmd->argv[i]);
			i++;
		}
		r = cmd->redir;
		while (r)
		{
			printf(" redir: type=%d target=%s\n", r->type, r->target);
			r = r->next;
		}
		cmd = cmd->next;
	}
}
