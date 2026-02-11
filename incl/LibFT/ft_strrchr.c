/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:56:42 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/11 20:39:12 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		v;
	const char	*last;

	v = (char)c;
	last = NULL;
	while (*s != '\0')
	{
		if (*s == v)
			last = s;
		s++;
	}
	if (v == '\0')
		return ((char *)s);
	return ((char *)last);
}

// int main(void)
// {
// 	char s[] = "Feet first into hell, troopers!";
// 	int c = 'e';

// 	printf("\n%s\n", ft_strrchr(s, c));
// 	printf("%s\n\n", strrchr(s, c));
// 	return 0;
// }
