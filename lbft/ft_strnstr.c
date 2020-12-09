/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:03:09 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/25 19:53:19 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *tofind, size_t len)
{
	size_t		k;
	const char	*deb;
	const char	*fin;

	if (*tofind == '\0')
		return (char*)src;
	while (*src != '\0' && len > 0)
	{
		deb = src;
		fin = tofind;
		k = len;
		while (*src && *fin && *src == *fin && k > 0)
		{
			src++;
			fin++;
			k--;
		}
		if (*fin == '\0')
			return ((char *)deb);
		src = deb + 1;
		len--;
	}
	return (0);
}
