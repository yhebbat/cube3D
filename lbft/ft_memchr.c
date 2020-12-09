/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:40:19 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/26 15:04:14 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t l)
{
	size_t				i;
	const unsigned char	*str;

	str = s;
	i = 0;
	while (i < l)
	{
		if (str[i] == (unsigned char)c)
			return (void *)(s + i);
		i++;
	}
	return (0);
}
