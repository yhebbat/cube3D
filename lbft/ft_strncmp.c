/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:57:51 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/25 19:52:52 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*ss1;
	unsigned char		*ss2;

	ss2 = (unsigned char *)s2;
	ss1 = (unsigned char *)s1;
	i = 0;
	if (n == 0)
		return (0);
	while (ss1[i] == ss2[i] && i < n - 1 && s1[i] && s2[i])
		i++;
	return (ss1[i] - ss2[i]);
}
