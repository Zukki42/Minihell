/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:34:57 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/12 22:02:45 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		v;

	v = (unsigned char)c;
	p = (const unsigned char *)s;
	while (n--)
	{
		if (*p == v)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char s[] = "Cop Cuties, cute and on-duty~";
// 	int c = 'd';
// 	int n = 25;

// 	printf("\n%s\n", ft_memchr(s, c, n));
// 	printf("%s\n\n", memchr(s, c, n));
// 	return 0;
// }
