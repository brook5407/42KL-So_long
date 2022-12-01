/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:54:23 by chchin            #+#    #+#             */
/*   Updated: 2022/06/10 09:21:19 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printf_char(int c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

static void	ft_printf_format(const char fmt, va_list args, int *len)
{
	if (fmt == 'c')
		ft_printf_char(va_arg(args, int), len);
	else if (fmt == 's')
		ft_printf_str(va_arg(args, char *), len);
	else if (fmt == 'i' || fmt == 'd')
		ft_printf_nbr(va_arg(args, int), len);
	else if (fmt == 'p')
		ft_printf_ptr(va_arg(args, void *), len);
	else if (fmt == 'u')
		ft_printf_unsigned(va_arg(args, unsigned int), len);
	else if (fmt == 'x' || fmt == 'X')
		ft_printf_hex(va_arg(args, unsigned int), len, fmt);
	else if (fmt == '%')
		ft_printf_char('%', len);
}

int	ft_printf(const char *fmt, ...)
{
	int		printf_len;
	va_list	args;

	printf_len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			ft_printf_format(*++fmt, args, &printf_len);
		}
		else
			ft_printf_char(*fmt, &printf_len);
		fmt++;
	}
	va_end(args);
	return (printf_len);
}
