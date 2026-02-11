/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:34:27 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/11 18:23:25 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks string for Pable chars,
// if all are Pable it'll return 1, otherwise 0

#include "libft.h"

int	ft_isprint(int c)
{
	if (!(c >= 32 && c <= 126))
		return (0);
	else
		return (1);
}

// int main()
// {
// 	int c = ' ';

// 	printf("\n%d\n\n", ft_isprint(c));
// 	return (0);
// }
