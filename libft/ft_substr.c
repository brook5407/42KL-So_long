/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:39:33 by chchin            #+#    #+#             */
/*   Updated: 2022/05/17 10:15:19 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strlen;
	size_t	dstsize;
	char	*dst;

	if (!s)
		return (0);
	strlen = ft_strlen(s);
	dstsize = 0;
	if (start < strlen)
		dstsize = strlen - start;
	if (dstsize > len)
		dstsize = len;
	dst = malloc(sizeof(char) * dstsize + 1);
	if (!dst)
		return (0);
	ft_strlcpy(dst, s + start, dstsize + 1);
	return (dst);
}
