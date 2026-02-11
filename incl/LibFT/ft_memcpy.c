/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:01:51 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/25 15:15:57 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

// int main(void)
// {
// 	char src[] = "Damn";
// 	char dst[] = "Daniel";
// 	char barrier[] = "------";

// 	printf("\n%s\n", src);
// 	printf("%s\n", dst);
// 	printf("%s\n", barrier);

// 	// ft_memcpy(dst, src, sizeof(src));
// 	ft_memcpy(dst, src, 5);

// 	printf("%s\n", src);
// 	printf("%s\n\n", dst);

// 	return (0);
// }
