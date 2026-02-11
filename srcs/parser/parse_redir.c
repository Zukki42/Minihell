/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:30:09 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/29 15:30:10 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redir_type	redir_type_from_token(t_tok_type type)
{
	if (type == T_REDIR_IN)
		return (R_IN);
	if (type == T_REDIR_OUT)
		return (R_OUT);
	if (type == T_REDIR_APPEND)
		return (R_APPEND);
	return (R_HEREDOC);
}

static int	add_redir_node(t_redir **list, t_redir_type type, char *target)
{
	t_redir	*node;
	t_redir	*cur;

	node = malloc(sizeof(t_redir));
	if (!node)
		return (1);
	node->type = type;
	node->target = ft_strdup(target);
	if (!node->target)
	{
		free(node);
		return (1);
	}
	node->heredoc_fd = -1;
	node->next = NULL;
	if (!*list)
	{
		*list = node;
		return (0);
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
	return (0);
}

int	parse_redir(t_redir **redir_list, t_token **tok)
{
	t_token	*redir_tok;
	t_token	*word_tok;
	int		err;

	err = 0;
	redir_tok = *tok;
	word_tok = redir_tok->next;
	if (!word_tok || word_tok->type != T_WORD)
		return (1);
	err = add_redir_node(redir_list,
			redir_type_from_token(redir_tok->type), word_tok->value);
	*tok = word_tok->next;
	return (err);
}
