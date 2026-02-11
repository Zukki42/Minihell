/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:05:42 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/11 18:23:16 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks string for numeric chars,
// if all are digits it'll return 1, otherwise 0

#include "libft.h"

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	else
		return (1);
}

// int main()
// {
// 	int c = '7';

// 	printf("\n%d\n\n", ft_isdigit(c));
// 	return (0);
// }
