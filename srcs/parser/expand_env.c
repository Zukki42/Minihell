/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:44:58 by bavirgil          #+#    #+#             */
/*   Updated: 2025/11/29 15:44:59 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_value(char **env, char *key)
{
	int	i;
	int	len;

	len = ft_strlen(key);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], key, len) && env[i][len] == '=')
			return (&env[i][len + 1]);
		i++;
	}
	return (NULL);
}

static char	*expand_status(t_shell *sh, int *i)
{
	(*i)++;
	return (ft_itoa(sh->last_status));
}

char	*expand_one(char *str, int *i, t_shell *sh)
{
	char	key[256];
	int		k;
	char	*value;

	(*i)++;
	if (str[*i] == '?')
		return (expand_status(sh, i));
	k = 0;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
	{
		key[k] = str[*i];
		k++;
		(*i)++;
	}
	key[k] = '\0';
	if (k == 0)
		return (ft_strdup("$"));
	value = get_env_value(sh->env, key);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}
