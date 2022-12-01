/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:54:11 by chchin            #+#    #+#             */
/*   Updated: 2022/06/10 10:03:55 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

void	ft_printf_char(int c, int *len);
void	ft_printf_str(char *s, int *len);
void	ft_printf_nbr(int n, int *len);
void	ft_printf_hex(unsigned long n, int *len, char fmt);
void	ft_printf_ptr(void *n, int *len);
void	ft_printf_unsigned(unsigned int n, int *len);
int		ft_printf(const char *fmt, ...);

#endif
