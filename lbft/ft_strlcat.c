/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 00:21:24 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/29 01:19:45 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t s_src;
	size_t k;

	k = 0;
	s_src = ft_strlen(src);
	if (!dst && size == 0)
		return (s_src);
	if (ft_strlen(dst) > size)
		s_src = s_src + size;
	else
		s_src = s_src + ft_strlen(dst);
	while (*dst && size != 0)
	{
		dst++;
		size--;
	}
	while (*src && 1 < size)
	{
		*dst++ = *src++;
		size--;
	}
	if (size != 0)
		*dst = '\0';
	return (s_src);
}
