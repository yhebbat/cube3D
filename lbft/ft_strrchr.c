/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:32:38 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/25 19:53:51 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	str;

	str = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != str)
	{
		i--;
		if (i < 0)
			return (0);
	}
	return ((char *)s + i);
}
