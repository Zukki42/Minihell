/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:16:13 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/17 17:51:37 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

// int main(void)
// {
// 	char str1[] = "I see the player you mean.";
// 	char str2[] = "Danila_LLITPEK?";
// 	char barrier[] = "--------------------------";
// 	int	eyes_of_ender = 3;

// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	printf("%s\n", barrier);

// 	ft_strlcpy(str2, str1, eyes_of_ender);

// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	printf("%zu\n", ft_strlcpy(str2, str1, eyes_of_ender));

// 	return (0);
// }
