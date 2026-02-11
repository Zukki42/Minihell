/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:00:33 by dstreck           #+#    #+#             */
/*   Updated: 2025/03/18 16:46:32 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// void	printf_tester(unsigned int i, char *c)
// {
// 	printf("\nIndex: %u, Char; %c\n", i, *c);
// }

// int main(void)
// {
// 	char str[] = "lol";
// 	ft_striteri(str, printf_tester);
// 	printf("\n");
// 	return 0;
// }
