/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:14:32 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/29 16:33:43 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	skip_single_quote(char *line, int i)
{
	i++;
	while (line[i] && line[i] != '\'')
		i++;
	if (line[i] == '\'')
		i++;
	return (i);
}

static int	skip_double_quote(char *line, int i)
{
	i++;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == '"')
		i++;
	return (i);
}

int	read_quoted_word(char *line, int i)
{
	while (line[i] && !is_space(line[i]) && !is_metachar(line[i]))
	{
		if (line[i] == '\'')
			i = skip_single_quote(line, i);
		else if (line[i] == '"')
			i = skip_double_quote(line, i);
		else
			i++;
	}
	return (i);
}

int	handle_word(char *line, int i, t_token **list)
{
	int	start;
	int	end;
	char	*value;

	start = i;
	end = read_quoted_word(line, i);
	value = ft_substr(line, start, end - start);
	if (!value)
		return (end);
	token_add_back(list, new_token(T_WORD, value));
	return (end);
}
