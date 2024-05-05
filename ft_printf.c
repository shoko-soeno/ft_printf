/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:34:38 by ssoeno            #+#    #+#             */
/*   Updated: 2024/05/05 20:50:07 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_format(const char specifier, va_list args)
{
	int	char_count;

	char_count = 0;
	if (specifier == 'c')
		char_count += ft_printf_char(va_arg(args, int)); // ASCII文字として渡される
	else if (specifier == 's')
		char_count += ft_printf_str(va_arg(args, char *)); // 文字列ポインタ
	else if (specifier == 'p')
		char_count += ft_printf_ptr(va_arg(args, void *)); // ポインタを16進数で
	else if (specifier == 'd' || specifier == 'i')
		char_count += ft_printf_int(va_arg(args, int)); // 符号付き整数
	else if (specifier == 'u')
		char_count += ft_printf_uint(va_arg(args, unsigned int)); // 符号なし整数
	else if (specifier == 'x' || specifier == 'X')
		char_count += ft_printf_hex(va_arg(args, unsigned int), specifier); // 大 or 小文字16進数
	else if (specifier == '%')
		ft_printf_percent();
	else
		return (-1);
	return (char_count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	count;
	va_list	args;

	va_start(args, str); //可変長引数リストを初期化
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%') //出力指定子を見つけたら
		{
			if (str[i + 1] == '%') //パーセンテージ記号のエスケープ
			{
				ft_putchar_fd('%', 1);
				count++;
				i++;//'%'の次の'%'をスキップ
			}
			else
			{
				count += handle_format(str[i + 1], args); //次の文字が指定子
				i++;
			}
		}
		else{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
