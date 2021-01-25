/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:12:55 by yhebbat           #+#    #+#             */
/*   Updated: 2021/01/21 15:13:56 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*list;

	list = NULL;
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = ft_strdup(content);
	list->next = NULL;
	return (list);
}
