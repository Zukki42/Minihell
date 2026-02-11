/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:53:39 by dstreck           #+#    #+#             */
/*   Updated: 2025/12/03 15:19:35 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	segment_counter(char const *s, char c)
{
	size_t	seg;

	seg = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			seg++;
		while (*s != c && *s)
			s++;
	}
	return (seg);
}

void	free_split(char **res)
{
	int	i;

	i = 0;
	if (res == NULL)
		return ;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	int		seg_len;
	int		i;

	i = 0;
	list = (char **)malloc((segment_counter(s, c) + 1) * (sizeof(char *)));
	if (list == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			seg_len = ft_strchr(s, c) - s;
			if (!ft_strchr(s, c))
				seg_len = ft_strlen(s);
			list[i] = ft_substr(s, 0, seg_len);
			if (list[i] == NULL)
				return (free_split(list), NULL);
			i++;
			s += seg_len;
		}
	}
	return (list[i] = NULL, list);
}
