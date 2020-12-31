/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:00:44 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/20 18:58:30 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int		ss1;
	unsigned int		ss2;
	char				*new;

	ss1 = 0;
	ss2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[ss1] != '\0')
		ss1++;
	while (s2[ss2] != '\0')
		ss2++;
	if (!(new = (char *)malloc((ss1 + ss2 + 1) * sizeof(char))))
		return (0);
	ft_memmove(new, s1, ss1);
	ft_memmove(new + ss1, s2, ss2);
	new[ss1 + ss2] = '\0';
	return (new);
}
