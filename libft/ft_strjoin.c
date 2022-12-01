/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:57:58 by chchin            #+#    #+#             */
/*   Updated: 2022/05/17 10:15:19 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, size);
	ft_strlcat(str, s2, size);
	return (str);
}
