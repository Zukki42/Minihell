/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:34:13 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/17 18:00:33 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

// int main(void)
// {
// 	char s1[] = "Ja pierdole!";
// 	char s2[] = "Bobr kurwa!";
// 	char barrier[] = "------------";
// 	printf("\n%s\n", s1);
// 	printf("%s\n", s2);
// 	printf("%s\n", barrier);
// 	printf("%d\n", strncmp(s1, s2, 20));
// 	printf("%d\n\n", ft_strncmp(s1, s2, 20));
// 	return (0);
// }
