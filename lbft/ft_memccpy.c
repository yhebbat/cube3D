/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:49:21 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/25 22:30:08 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*res;
	char	*acpy;

	i = 0;
	res = (char *)dest;
	acpy = (char *)src;
	while (i < n)
	{
		res[i] = acpy[i];
		if (res[i] == (char)c)
			return ((char *)(dest + i + 1));
		i++;
	}
	return (0);
}
