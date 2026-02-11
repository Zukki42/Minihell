/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:26:05 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/11 18:23:10 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks string for ascii chars,
// if all are ascii it'll return 1, otherwise 0

#include "libft.h"

int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
		return (0);
	else
		return (1);
}

// int main()
// {
// 	int c = 'H';

// 	printf("\n%d\n\n", ft_isascii(c));
// 	return (0);
// }
