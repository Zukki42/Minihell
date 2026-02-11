/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:41:43 by dstreck           #+#    #+#             */
/*   Updated: 2026/01/09 18:50:40 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit((unsigned char)str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

// int main(void)
// {
// 	char str[] = "    -2147483649dsfrg234";
// 	char barrier[] = "----------------------";
// 	printf("\n%s\n", str);
// 	printf("%s\n", barrier);
// 	printf("%ld\n\n", ft_atol(str));
// 	return (0);
// }
