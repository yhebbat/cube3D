/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:43:43 by yhebbat           #+#    #+#             */
/*   Updated: 2019/11/15 10:57:31 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	k;
	char	*new;
	size_t	i;

	i = 0;
	k = 0;
	while (s[k] != '\0')
		k++;
	if (!(new = (char *)malloc((k + 1) * sizeof(char))))
		return (0);
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
