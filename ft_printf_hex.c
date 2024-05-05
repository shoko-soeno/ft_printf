/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:50:55 by arosado-          #+#    #+#             */
/*   Updated: 2024/05/05 21:05:09 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_hex(unsigned int num, const char	specifier)
{
	const char	*hex_lower = "0123456789abcdef";
	const char	*hex_upper = "0123456789ABCDEF";
	const char	*hex_digits;
	int			count;

	count = 0;
	if (specifier == 'x')
	{
		hex_digits = hex_lower;
	} else if (specifier == 'X')
	{
		hex_digits = hex_upper;
	} else {
		return (-1);
	}
	if (num >= 16)
	{
		count += ft_printf_hex(num / 16, specifier);
	}
	ft_putchar_fd(hex_digits[num % 16], 1);
	return (count + 1);
}
