/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:41:33 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/26 04:14:34 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!(*alst))
		*alst = ft_lstnew(new);
	while ((*alst) != NULL)
		(*alst) = (*alst)->next;
	(*alst)->next = new;
}
