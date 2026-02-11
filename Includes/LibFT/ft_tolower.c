/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:26:59 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/15 17:07:01 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}

// int main(void)
// {
// 	int c = 'F';
// 	//int c = '8';

// 	printf("\n%c\n\n", ft_tolower(c));
// 	return (0);
// }
