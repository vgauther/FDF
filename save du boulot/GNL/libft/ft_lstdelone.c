/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:01:07 by vgauther          #+#    #+#             */
/*   Updated: 2017/12/04 13:01:09 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	void	*tmp;
	t_list	*list;

	list = *alst;
	tmp = (void *)list->content_size;
	del(list->content, list->content_size);
	free(list);
	list = list->next;
	*alst = NULL;
}
