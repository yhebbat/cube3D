/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:59:41 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/29 21:42:40 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (0);
	if (start < ft_strlen(s))
	{
		while (i < len && s[start])
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
	}
	else
		str[i] = '\0';
	return (str);
}
