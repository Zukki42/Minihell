/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:29:46 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/29 16:23:59 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const char	*token_str(t_token *tok)
{
	if (!tok)
		return ("newline");
	if (tok->type == T_PIPE)
		return ("|");
	if (tok->type == T_REDIR_IN)
		return ("<");
	if (tok->type == T_REDIR_OUT)
		return (">");
	if (tok->type == T_REDIR_APPEND)
		return (">>");
	if (tok->type == T_REDIR_HEREDOC)
		return ("<<");
	return (tok->value);
}

static int	print_syntax_error(t_token *tok)
{
	const char	*s;

	s = token_str(tok);
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd((char *)s, 2);
	ft_putstr_fd("'\n", 2);
	return (1);
}

static int	check_pipe_token(t_token *tok, t_shell *sh, t_token *prev)
{
	if (!prev || !tok->next || tok->next->type == T_PIPE)
	{
		print_syntax_error(tok);
		sh->last_status = 258;
		return (1);
	}
	return (0);
}

static int	check_redir_token(t_token *tok, t_shell *sh)
{
	if (!tok->next || tok->next->type != T_WORD)
	{
		if (tok->next)
    		print_syntax_error(tok->next);
		else
   		 	print_syntax_error(tok);		
	sh->last_status = 258;
		return (1);
	}
	return (0);
}

int	check_syntax(t_token *tok, t_shell *sh)
{
	t_token	*prev;

	prev = NULL;
	while (tok)
	{
		if (tok->type == T_PIPE)
		{
			if (check_pipe_token(tok, sh, prev))
				return (1);
		}
		else if (is_redir_token(tok))
		{
			if (check_redir_token(tok, sh))
				return (1);
		}
		prev = tok;
		tok = tok->next;
	}
	return (0);
}
