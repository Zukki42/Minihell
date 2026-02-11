/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:38:53 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/29 15:31:33 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*parse_line(char *line, t_shell *sh)
{
	t_token	*tokens;
	t_cmd	*cmds;

	if (!line || !*line)
		return (NULL);
	tokens = lex_line(line);
	if (!tokens)
		return (NULL);
	expand_tokens(tokens, sh);
	if (check_syntax(tokens, sh))
	{
		free_tokens(tokens);
		return (NULL);
	}
	cmds = parse_tokens_to_cmds(tokens);
	free_tokens(tokens);
	debug_print_cmds(cmds);
	return (cmds);
}
