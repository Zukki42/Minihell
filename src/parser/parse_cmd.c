/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:30:21 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/29 15:30:21 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**argv_add(char **old, char *value)
{
	char	**new;
	int		size;
	int		i;

	size = argv_size(old);
	new = malloc(sizeof(char *) * (size + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = old[i];
		i++;
	}
	new[size] = ft_strdup(value);
	if (!new[size])
	{
		free(new);
		return (NULL);
	}
	new[size + 1] = NULL;
	free(old);
	return (new);
}

static t_cmd	*cmd_from_argv_redir(char **argv, t_redir *redir)
{
	t_cmd	*cmd;

	if (!argv && !redir)
		return (NULL);
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
	{
		free(argv);
		return (NULL);
	}
	cmd->argv = argv;
	cmd->redir = redir;
	cmd->next = NULL;
	return (cmd);
}

static int	process_token(t_token **cur, char ***argv, t_redir **redir)
{
	if (is_redir_token(*cur))
	{
		if (parse_redir(redir, cur) != 0)
			return (1);
	}
	else if ((*cur)->type == T_WORD)
	{
		*argv = argv_add(*argv, (*cur)->value);
		if (!*argv)
			return (1);
		*cur = (*cur)->next;
	}
	else
		*cur = (*cur)->next;
	return (0);
}

t_cmd	*parse_one_command(t_token **tok)
{
	char	**argv;
	t_redir	*redir;
	t_token	*cur;

	argv = NULL;
	redir = NULL;
	cur = *tok;
	while (cur && cur->type != T_PIPE)
	{
		if (process_token(&cur, &argv, &redir) != 0)
			return (NULL);
	}
	*tok = cur;
	return (cmd_from_argv_redir(argv, redir));
}

t_cmd	*parse_tokens_to_cmds(t_token *tok)
{
	t_cmd	*head;
	t_cmd	*last;
	t_cmd	*cur_cmd;

	head = NULL;
	last = NULL;
	while (tok)
	{
		if (tok->type == T_PIPE)
		{
			tok = tok->next;
			continue ;
		}
		cur_cmd = parse_one_command(&tok);
		if (!cur_cmd)
			return (NULL);
		if (!head)
			head = cur_cmd;
		else
			last->next = cur_cmd;
		last = cur_cmd;
	}
	return (head);
}
