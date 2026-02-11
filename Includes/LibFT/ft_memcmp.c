/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:38:54 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/18 20:39:35 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
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
// 	printf("%d\n", memcmp(s1, s2, 20));
// 	printf("%d\n\n", ft_memcmp(s1, s2, 20));
// 	return (0);
// }
