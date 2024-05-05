/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:35:25 by ssoeno            #+#    #+#             */
/*   Updated: 2024/05/05 20:51:27 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
//# include <limits.h>

int	ft_printf(const char *str, ...);
int handle_format(const char specifier, va_list args);
int	ft_printf_char(char c);
int	ft_printf_str(char *s);
int	ft_printf_int(int n);
int	ft_printf_ptr(void *ptr);
int	ft_printf_uint(unsigned int n);
int	ft_printf_hex(unsigned int n, const char specifier);
void	ft_printf_percent(void);

#endif