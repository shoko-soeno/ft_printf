/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:27:31 by ssoeno            #+#    #+#             */
/*   Updated: 2024/05/05 21:06:51 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h> //uintptr_tを使うため

// static int	ft_printf_hex(uintptr_t num)
// {
// 	char *hex_digits;
// 	int count;

// 	*hex_digits = "0123456789abcdef";
// 	count = 0;
// 	if (num >= 16)
// 	{
// 		count += ft_printf_hex(num / 16);
// 	}
// 	ft_putchar_fd(hex_digits[num % 16], 1);
// 	return count + 1;
// }

int	ft_printf_ptr(void *ptr)
{
	uintptr_t ptr_val;
	int count;

	ptr_val = (uintptr_t)ptr;
	count = 0;
	write(1, "0x", 2);
	count += 2;
	if (ptr == NULL)
	{
		write(1, "0", 1);
		return count + 1;
	}
	count += ft_printf_hex(ptr_val, 'x');
	return count;
}
