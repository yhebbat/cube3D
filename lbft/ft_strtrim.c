/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:41:20 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/27 23:11:12 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_mninghatbda(char const *s1, char const *set)
{
	int dev;
	int i;

	dev = 0;
	while (s1[dev] != '\0')
	{
		i = 0;
		while (s1[dev] != set[i] && set[i] != '\0')
			i++;
		if (s1[dev] == set[i])
			dev++;
		else
			break ;
	}
	return (dev);
}

static int		ft_finghatsali(char const *s1, char const *set, int dev)
{
	int der;
	int i;

	der = ft_strlen(s1);
	i = 0;
	while (der >= dev)
	{
		i = 0;
		while (s1[der] != set[i] && set[i] != '\0')
			i++;
		if (s1[der] == set[i])
			der--;
		else
			break ;
	}
	return (der);
}

static	char	*ft_l9alb(char const *s1)
{
	int		i;
	char	*fin;

	i = 0;
	if (!(fin = malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (0);
	while (i < (int)ft_strlen(s1))
	{
		fin[i] = s1[i];
		i++;
	}
	fin[i] = '\0';
	return (fin);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*fin;
	int		dev;
	int		der;
	int		i;
	int		s;

	if (s1 == NULL)
		return (0);
	if (s1 && !set)
		return (ft_l9alb(s1));
	dev = ft_mninghatbda(s1, set);
	der = ft_finghatsali(s1, set, dev);
	i = 0;
	s = der - dev + 1;
	if (!(fin = (char *)malloc((s + 1) * sizeof(char))))
		return (0);
	while (i < s)
	{
		fin[i] = s1[dev];
		i++;
		dev++;
	}
	fin[i] = '\0';
	return (fin);
}
