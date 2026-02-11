/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:40:07 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/17 17:27:19 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= slen)
	{
		str = ft_calloc(1, sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > slen - start)
		len = slen - start;
	str = ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] != 0 && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

// int main(void)
// {
// 	char s[] = "Get da substring outta hea!";

// 	printf("\n%s\n\n", ft_substr(s, 7, 9));

// 	return 0;
// }
