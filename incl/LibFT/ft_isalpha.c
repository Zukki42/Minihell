/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:02:51 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/11 18:23:04 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks string for alphabetic chars,
// if all are either lower- or uppercase it'll return 1, otherwise 0

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c < 65 || c > 122 || (c >= 91 && c <= 96))
		return (0);
	else
		return (1);
}

// int main()
// {
// 	int c = '!';

// 	printf("\n%d\n\n", ft_isalpha(c));
// 	return (0);
// }
