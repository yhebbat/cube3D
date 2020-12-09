/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:27:44 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/21 16:42:29 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	char		*ssrc;

	dst = (char *)dest;
	ssrc = (char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	if (ssrc > dst)
		ft_memcpy(dst, ssrc, n);
	else
	{
		dst = (char *)dest + (n - 1);
		ssrc = (char *)src + (n - 1);
		while (n > 0)
		{
			*(dst--) = *(ssrc--);
			n--;
		}
	}
	return (dest);
}
