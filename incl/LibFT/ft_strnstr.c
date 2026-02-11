/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:40:22 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/26 21:14:41 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;
	size_t	c;
	char	*h;

	i = 0;
	n_len = 0;
	h = (char *)haystack;
	n_len = ft_strlen(needle);
	if (!n_len || haystack == needle)
		return (h);
	if (len < ft_strlen(needle) && !(!haystack))
		return (NULL);
	while (i <= len - n_len && *haystack != '\0')
	{
		c = 0;
		while (h[i + c] != '\0' && needle[c] != '\0'
			&& h[i + c] == needle[c] && i + c < len)
			c++;
		if (c == n_len)
			return (h + i);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char s[] = "BEHOLD! THE POWER OF AN ANGEL!";
// 	char c[] = "PO";
// 	int n = 14;

// 	printf("\n%s\n", ft_strnstr(s, c, n));
// 	printf("%s\n\n", strnstr(s, c, n));
// 	return 0;
// }
