/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:10:03 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/25 22:27:51 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	char				*res;
	const char			*acpy;

	i = 0;
	res = dest;
	acpy = src;
	if (res == NULL && acpy == NULL)
		return (0);
	if (ft_memcmp(res, acpy, n) != 0)
	{
		while (i < n)
		{
			res[i] = acpy[i];
			i++;
		}
	}
	return (dest);
}
