/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:55:32 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/18 21:05:51 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digits(int n)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (i);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i - 1);
}

char	*ft_itoa(int n)
{
	size_t		d;
	char		*str;
	long int	num;

	num = n;
	d = digits(n);
	if (n < 0)
	{
		num = -num;
		d++;
	}
	str = (char *)malloc(sizeof(char) * (d + 1));
	if (str == NULL)
		return (NULL);
	*(str + d) = 0;
	while (d--)
	{
		*(str + d) = num % 10 + 48;
		num = num / 10;
	}
	if (n < 0)
		*(str + 0) = 45;
	return (str);
}

// int main(void)
// {
// 	printf("\n%s\n\n", ft_itoa(15654));
// 	return 0;
// }
