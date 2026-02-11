/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:12:17 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/11 19:54:16 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// int main(void)
// {
// 	char str[] = "See ya in the major leagues, Jack.";
// 	char barrier[] = "----------------------------------";

// 	printf("\n%s\n", str);
// 	printf("%s\n", barrier);
// 	ft_bzero(str, sizeof(str));
// 	printf("%s\n\n", str);

// 	return (0);
// }
