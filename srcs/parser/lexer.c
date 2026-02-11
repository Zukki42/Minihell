/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:57:01 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/29 16:33:40 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_pipe(char *line, int i, t_token **list)
{
	(void)line;
	token_add_back(list, new_token(T_PIPE, NULL));
	return (i + 1);
}

static int	select_in_redir(char *line, int i, t_tok_type *type)
{
	if (line[i + 1] == '<')
	{
		*type = T_REDIR_HEREDOC;
		return (i + 2);
	}
	*type = T_REDIR_IN;
	return (i + 1);
}

static int	select_out_redir(char *line, int i, t_tok_type *type)
{
	if (line[i + 1] == '>')
	{
		*type = T_REDIR_APPEND;
		return (i + 2);
	}
	*type = T_REDIR_OUT;
	return (i + 1);
}

static int	handle_redir(char *line, int i, t_token **list)
{
	t_tok_type	type;
	int		start;
	int		end;
	char		*value;

	start = i;
	if (line[i] == '<')
		end = select_in_redir(line, i, &type);
	else
		end = select_out_redir(line, i, &type);
	value = ft_substr(line, start, end - start);
	if (!value)
		return (end);
	token_add_back(list, new_token(type, value));
	return (end);
}

t_token	*lex_line(char *line)
{
	t_token	*list;
	int	i;

	list = NULL;
	i = 0;
	while (line[i])
	{
		if (is_space(line[i]))
			i++;
		else if (line[i] == '|')
			i = handle_pipe(line, i, &list);
		else if (line[i] == '<' || line[i] == '>')
			i = handle_redir(line, i, &list);
		else
			i = handle_word(line, i, &list);
	}
	return (list);
}
