/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:28:23 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/21 16:14:53 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	str;

	str = (unsigned char)c;
	i = 0;
	while (s[i] != str)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)s + i);
}

int		remplir_line(char **line, char **str, int len)
{
	char	*tmp;

	if (!(*line = ft_substr(*str, 0, len)))
		return (-1);
	if (!(tmp = ft_strdup((*str) + len + 1)))
		return (-1);
	free(*str);
	if (!(*str = ft_strdup(tmp)))
		return (-1);
	free(tmp);
	return (1);
}

int		remplir_fin(char **line, char **str)
{
	if (!(*line = ft_strdup(*str)))
		return (-1);
	free(*str);
	*str = NULL;
	return (0);
}

int		ft_read(int fd, char **str)
{
	char	*buff;
	char	*tmp;
	int		ret;

	if (!(buff = malloc(BUFFER_SIZE + 1 * sizeof(char))))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strdup(*str)))
			return (-1);
		free(*str);
		*str = NULL;
		if (!((*str) = ft_strjoin(tmp, buff)))
			return (-1);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(buff);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;
	int			len;

	len = 0;
	if (fd < 0)
		return (-1);
	if (str == NULL)
	{
		if (!(str = ft_strdup("")))
			return (-1);
	}
	ret = ft_read(fd, &str);
	if (ret < 0)
		return (-1);
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
	{
		return (remplir_line(line, &str, len));
	}
	else if (str[len] == '\0')
		return (remplir_fin(line, &str));
	return (0);
}
