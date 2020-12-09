/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:24:02 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/25 20:09:01 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int c)
{
	unsigned int		nb;
	unsigned int		i;
	char				*str;

	nb = c;
	i = 0;
	if (c <= 0)
	{
		nb = -c;
		i = 1;
	}
	i += ft_intlen(nb);
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (c < 0)
		str[0] = '-';
	return (str);
}
