/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:27:31 by ssoeno            #+#    #+#             */
/*   Updated: 2024/05/06 23:08:46 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h> //uintptr_tを使うため

int ft_printf_ptr_hex(uintptr_t num)
{
	const char *hex_digits = HEX_LOWER;
	char buffer[16 + 1]; // long enough for 64-bit address + null terminator
	int index = 16;
	buffer[index--] = '\0'; // null terminate the string
	if (num == 0)
		buffer[index--] = '0'; // handle zero explicitly
	while (num != 0) {
		buffer[index--] = hex_digits[num % 16];
		num /= 16;
	}
	int start = index + 1; // calculate needed padding for 64-bit addresses
	// Print the rest of the hex number
	while (buffer[start]) {
		ft_putchar_fd(buffer[start++], 1);
	}
	return (16 - index - 1); // return the number of characters printed, assuming fixed size for pointer
}

int	ft_printf_ptr(void *ptr)
{
	uintptr_t	ptr_val;
	int			count;

	ptr_val = (uintptr_t)ptr;
	count = 2;
	write(1, "0x", 2);
	count += ft_printf_ptr_hex(ptr_val);
	return count;
}

/* */
// void	ft_putnbr_base_fd(unsigned long nbr, char *base, int fd, int *count)
// {
// 	unsigned long		base_len;

// 	base_len = (unsigned long)ft_strlen(base);
// 	if (nbr >= base_len)
// 		ft_putnbr_base_fd(nbr / base_len, base, fd, count);
// 	ft_putchar_fd(base[nbr % base_len], fd);
// 	(*count)++;
// }

// int	ft_put_p(void *ptr)
// {
// 	int				count;
// 	unsigned long	nbr;

// 	nbr = (unsigned long)ptr;
// 	ft_putstr_fd("0x", 1);
// 	count = 2;
// 	ft_putnbr_base_fd(nbr, HEX_LOW, 1, &count);
// 	return (count);
// }