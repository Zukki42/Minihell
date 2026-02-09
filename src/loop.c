/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:38:06 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/27 19:06:33 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell_loop(t_shell *sh)
{
	char	*line;
	t_cmd	*cmds;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (*line)
			add_history(line);
		cmds = parse_line(line, sh);
		/* later: your friend will call exec here with cmds */
		if (cmds)
			free_cmd_list(cmds);
		free(line);
		(void)sh;
	}
	return (0);
}
