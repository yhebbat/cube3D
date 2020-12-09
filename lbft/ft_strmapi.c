/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:30:46 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/29 21:37:32 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	l;
	char			*mal;

	if (s == NULL)
		return (0);
	i = 0;
	l = ft_strlen(s);
	if (!(mal = (char *)malloc((l + 1) * sizeof(char))))
		return (0);
	while (s[i])
	{
		mal[i] = (*f)(i, s[i]);
		i++;
	}
	mal[i] = '\0';
	return (mal);
}
