/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:32:14 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/25 20:46:18 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *str;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(str = (char *)malloc(count * size)))
		return (0);
	ft_bzero(str, (count * size));
	return (str);
}
