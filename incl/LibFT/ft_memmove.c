/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:53:43 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/17 15:44:44 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (len == 0 || d == s)
		return (dst);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*(--d) = *(--s);
	}
	return (dst);
}

// int main(void)
// {
// 	char src[] = "Rock and Stone!";
// 	char dst[] = "For Karl!";
// 	char barrier[] = "------";

// 	printf("\n%s\n", src);
// 	printf("%s\n", dst);
// 	printf("%s\n", barrier);

// 	ft_memmove(dst, src, 4);
// 	// memmove(dst, src, 4);

// 	printf("%s\n", src);
// 	printf("%s\n\n", dst);

// 	return (0);
// }
