/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:09:32 by ssoeno            #+#    #+#             */
/*   Updated: 2024/05/05 21:07:34 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_uint(unsigned int n)
{
	unsigned long	nb;
	int		count;

	nb = (unsigned long)n;
	count = 0;
	if (nb > 9)
	{
		count += ft_printf_uint(nb / 10); //再帰的に左の桁を処理
		// ft_putchar_fd((nb % 10) + '0', fd);
	}
	ft_putchar_fd((nb % 10) + '0', 1);
	return (count + 1); //最後の桁のための1増やす
}
