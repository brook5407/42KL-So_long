/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptintf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:28:14 by chchin            #+#    #+#             */
/*   Updated: 2022/06/10 09:19:25 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printf_str(char *s, int *len)
{
	if (!s)
		ft_printf_str("(null)", len);
	else
	{
		while (*s)
			ft_printf_char(*s++, len);
	}
}

void	ft_printf_nbr(int n, int *len)
{
	char	*nbr;

	nbr = ft_itoa(n);
	ft_printf_str(nbr, len);
	free(nbr);
}

void	ft_printf_hex(unsigned long n, int *len, char fmt)
{
	if (n > 15)
	{
		ft_printf_hex(n / 16, len, fmt);
		ft_printf_hex(n % 16, len, fmt);
	}
	else
	{
		if (n < 10)
			ft_printf_char(n + '0', len);
		else if (fmt == 'x' && n > 9)
			ft_printf_char(n - 10 + 'a', len);
		else if (fmt == 'X' && n > 9)
			ft_printf_char(n - 10 + 'A', len);
	}
}

void	ft_printf_ptr(void *n, int *len)
{
	ft_printf_str("0x", len);
	ft_printf_hex((unsigned long)n, len, 'x');
}

void	ft_printf_unsigned(unsigned int n, int *len)
{
	if (n > 9)
	{
		ft_printf_unsigned(n / 10, len);
		ft_printf_unsigned(n % 10, len);
	}
	else
		ft_printf_char(n + '0', len);
}
