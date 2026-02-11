/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:31:16 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/17 17:13:47 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	v;

	v = (char)c;
	while (*s)
	{
		if (*s == v)
			return ((char *)s);
		s++;
	}
	if (v == '\0')
		return ((char *)s);
	return (NULL);
}

// int main(void)
// {
// 	char s[] = "Yippie ki yay, motherfucker";
// 	int c = '\0';

// 	printf("\n%s\n", ft_strchr(s, c));
// 	printf("%s\n\n", strchr(s, c));
// 	return 0;
// }
