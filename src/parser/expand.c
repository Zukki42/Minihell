/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:45:16 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/29 15:45:47 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_double(char *str, int *i, t_shell *sh)
{
	char	*res;
	char	*tmp;
	char	*tmp2;

	res = ft_strdup("");
	(*i)++;
	while (str[*i] && str[*i] != '"')
	{
		if (str[*i] == '$')
		{
			tmp = expand_one(str, i, sh);
			tmp2 = ft_strjoin(res, tmp);
			free(res);
			free(tmp);
			res = tmp2;
		}
		else
		{
			tmp = ft_substr(str, *i, 1);
			tmp2 = ft_strjoin(res, tmp);
			free(res);
			free(tmp);
			res = tmp2;
			(*i)++;
		}
	}
	if (str[*i] == '"')
		(*i)++;
	return (res);
}

static char	*expand_unquoted(char *str, int *i, t_shell *sh)
{
	char	*res;
	char	*tmp;
	char	*tmp2;

	res = ft_strdup("");
	while (str[*i] && str[*i] != '\'' && str[*i] != '"'
		&& !is_metachar(str[*i]) && !is_space(str[*i]))
	{
		if (str[*i] == '$')
		{
			tmp = expand_one(str, i, sh);
			tmp2 = ft_strjoin(res, tmp);
			free(res);
			free(tmp);
			res = tmp2;
		}
		else
		{
			tmp = ft_substr(str, *i, 1);
			tmp2 = ft_strjoin(res, tmp);
			free(res);
			free(tmp);
			res = tmp2;
			(*i)++;
		}
	}
	return (res);
}

static char	*expand_value(char *str, t_shell *sh)
{
	char	*res;
	char	*tmp;
	char	*tmp2;
	int		i;
	int		start;

	res = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			start = i;
			while (str[i] && str[i] != '\'')
				i++;
			tmp = ft_substr(str, start, i - start);
			tmp2 = ft_strjoin(res, tmp);
			free(tmp);
			free(res);
			res = tmp2;
			if (str[i] == '\'')
				i++;
		}
		else if (str[i] == '"')
		{
			tmp = expand_double(str, &i, sh);
			tmp2 = ft_strjoin(res, tmp);
			free(tmp);
			free(res);
			res = tmp2;
		}
		else
		{
			tmp = expand_unquoted(str, &i, sh);
			tmp2 = ft_strjoin(res, tmp);
			free(tmp);
			free(res);
			res = tmp2;
		}
	}
	return (res);
}

int	expand_tokens(t_token *tok, t_shell *sh)
{
	char	*new;

	while (tok)
	{
		if (tok->type == T_WORD)
		{
			new = expand_value(tok->value, sh);
			free(tok->value);
			tok->value = new;
		}
		tok = tok->next;
	}
	return (0);
}
