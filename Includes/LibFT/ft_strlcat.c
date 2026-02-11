/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:20:21 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/19 20:50:00 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	cpy;
	size_t	v;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (i >= dstsize)
		return (dstsize + j);
	v = 0;
	cpy = dstsize - i - 1;
	while (v < cpy && src[v] != '\0')
	{
		dst[i + v] = src[v];
		v++;
	}
	dst[i + v] = '\0';
	return (i + j);
}

// int main(void)
// {
// 	char dst[] = "A horrible chill goes down your spine...";
// 	char src[] = "Screams echo around you...";
// 	char barrier[] = "--------------------------";

// 	printf("\n%s\n", dst);
// 	printf("%s\n", src);
// 	printf("%s\n", barrier);
// 	printf("%zu\n\n", ft_strlcat(dst, src, sizeof(dst)));

// 	return (0);
// }
