/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstreck <dstreck@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:10:45 by dstreck           #+#    #+#             */
/*   Updated: 2026/01/16 16:08:12 by dstreck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hlp_putstr(char *str)
{
	int	count;
	int	temp;

	temp = 0;
	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		temp += write(1, str++, 1);
		if (temp == -1)
			return (-1);
		count = temp;
	}
	return (count);
}

int	hlp_un_signed_dec_num(long int n, int s)
{
	int	count;
	int	temp;

	temp = 0;
	count = 0;
	if (s && n < 0)
	{
		temp += write(1, "-", 1);
		if (temp == -1)
			return (-1);
		count = temp;
		n = -n;
	}
	if (n >= 10)
	{
		temp = hlp_un_signed_dec_num(n / 10, s);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count + write(1, &(char){(n % 10) + '0'}, 1));
}

int	hlp_unsigned_hex_num(size_t n, int u, int is_p)
{
	const char	*digits;
	int			count;
	int			temp;

	temp = 0;
	count = 0;
	if (u == 1)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (is_p == 1)
	{
		temp += write(1, "0x", 2);
		if (temp == -1)
			return (-1);
		count = temp;
	}
	if (n >= 16)
	{
		temp = hlp_unsigned_hex_num(n / 16, u, 0);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count + write(1, &digits[n % 16], 1));
}

int	hlp_cases(va_list args, const char c, int count, void *ptr)
{
	count = 0;
	if (c == 'c')
		count = write(1, &(char){va_arg(args, int)}, 1);
	if (c == 's')
		count += hlp_putstr(va_arg(args, char *));
	if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			count = write(1, PTRNULL, PTRNULL_LEN);
		else
			count += hlp_unsigned_hex_num((size_t)va_arg(args, size_t), 0, 1);
	}
	if (c == 'd' || c == 'i')
		count += hlp_un_signed_dec_num(va_arg(args, int), 1);
	if (c == 'u')
		count += hlp_un_signed_dec_num(va_arg(args, unsigned int), 0);
	if (c == 'x')
		count += hlp_unsigned_hex_num(va_arg(args, unsigned int), 0, 0);
	if (c == 'X')
		count += hlp_unsigned_hex_num(va_arg(args, unsigned int), 1, 0);
	if (c == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		temp;
	int		i;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		temp = 0;
		if (str[i] == '%' && str[i + 1] != '\0')
			temp += hlp_cases(args, str[++i], 0, NULL);
		else
			temp = write(1, &str[i], 1);
		if (temp == -1)
			return (-1);
		count += temp;
		i++;
	}
	return (va_end(args), count);
}

// int main(void)
// {
// 	int i = 0;
// 	int j = 0;
// 	i = ft_printf("%d\n", 10000);
// 	j = printf("%d\n", 10000);
// 	ft_printf("%d", i);
// 	printf("\n%d\n", j);
// }
