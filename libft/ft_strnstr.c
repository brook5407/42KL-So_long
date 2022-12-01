/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:50:50 by chchin            #+#    #+#             */
/*   Updated: 2022/05/17 10:15:19 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	char	*hay;
	char	*need;

	needle_len = ft_strlen(needle);
	hay = (char *)haystack;
	need = (char *)needle;
	if (needle_len == 0 || haystack == needle)
		return (hay);
	if (ft_strlen(haystack) == 0)
		return (0);
	while (len-- >= needle_len && *hay)
	{
		if (*hay == *need && (ft_strncmp(hay, need, needle_len) == 0))
			return (hay);
		++hay;
	}
	return (0);
}
