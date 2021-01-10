/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:28:45 by yhebbat           #+#    #+#             */
/*   Updated: 2019/11/15 11:51:56 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

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