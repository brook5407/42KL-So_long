/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:51:31 by chchin            #+#    #+#             */
/*   Updated: 2022/05/17 10:15:19 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*srcs;

	if (src == NULL && dst == NULL)
		return (NULL);
	dest = (char *)dst;
	srcs = (char *)src;
	while (n--)
		*dest++ = *srcs++;
	return (dst);
}
