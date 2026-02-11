/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:45:38 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/10 19:12:09 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Replaces chars in an array with specified chars for a 
// specified length after the specified index excluding 
// the index itself.

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = b;
	i = 0;
	while (i < len)
	{
		*p = c;
		p++;
		i++;
	}
	return (b);
}

// int	main(void)
// {
// 	int i = 0;
// 	char str1[] = "In the first age, in the first battle...";

// 	ft_memset(str1 + 7, '-', 5*sizeof(char));

// 	while (str1[i] != '\0')
// 	{
// 		write(1, &str1[i], 1);
// 		i++;
// 	}
// 	return (0);
// }
