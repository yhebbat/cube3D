/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 01:24:21 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/28 03:35:26 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int			ft_mots(char const *s, char c)
{
	int			i;
	int			k;
	int			p;

	i = 0;
	k = 0;
	p = 1;
	while (s[i])
	{
		if (s[i] == c)
			p = 1;
		else if (p == 1)
		{
			p = 0;
			k++;
		}
		i++;
	}
	return (k);
}

static void			*ft_freee(char **p, int j)
{
	while (p[j--])
		free(p[j]);
	free(p);
	return (0);
}

static int			ft_alpha(char const *s, char c, int i)
{
	int r;

	r = 0;
	while (s[i] != c)
	{
		r++;
		i++;
	}
	return (r);
}

static char			**ft_remp(char **p, char const *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i] && ft_mots(s, c) > j)
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(p[j] = malloc(sizeof(char) * ft_alpha(s, c, i))))
			return (ft_freee(p, j));
		while (s[i] != c)
			p[j][k++] = s[i++];
		p[j][k] = '\0';
		j++;
	}
	p[j] = 0;
	return (p);
}

char				**ft_split(const char *s, char c)
{
	char	**p;

	if (s == NULL)
		return (0);
	if (!(p = malloc(sizeof(char *) * (ft_mots(s, c) + 1))))
		return (0);
	return (ft_remp(p, s, c));
}