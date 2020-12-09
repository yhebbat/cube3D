/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 00:18:38 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/25 19:55:57 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	char	*deb;
	size_t	l;
	size_t	s_src;
	size_t	s_dst;

	s_dst = 0;
	s_src = 0;
	deb = dest;
	l = 0;
	s_src = ft_strlen(src);
	if (len != 0)
	{
		while (l + 1 < len && src[l] != '\0')
		{
			dest[l] = src[l];
			l++;
		}
		dest[l] = '\0';
	}
	if (s_src > len)
		return (s_src);
	return (l);
}
