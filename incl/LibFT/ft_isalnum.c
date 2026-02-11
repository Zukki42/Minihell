/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:09:40 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/11 19:36:19 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks string for alpha-numeric chars,
// if all are alpha-numeric it'll return 1, otherwise 0

#include "libft.h"

int	ft_isalnum(int c)
{
	if (!((c >= 48 && c <= 57)
			|| (c >= 65 && c <= 90)
			|| (c >= 97 && c <= 122)))
		return (0);
	else
		return (1);
}

// int main()
// {
// 	int c = '3';

// 	printf("\n%d\n\n", ft_isalnum(c));
// 	return (0);
// }
