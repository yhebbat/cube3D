/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:51:03 by yhebbat           #+#    #+#             */
/*   Updated: 2019/10/26 04:20:22 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *asup;

	asup = *lst;
	while (asup)
	{
		tmp = asup;
		asup = asup->next;
		if (tmp->content && del)
			(*del)(tmp->content);
		free(tmp);
	}
	asup->next = NULL;
}
