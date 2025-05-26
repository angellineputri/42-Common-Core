/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:06:11 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/21 15:19:42 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*end;
	t_list	*new;

	new_list = NULL;
	end = NULL;
	while (lst)
	{
		new = malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = NULL;
		if (!new_list)
			new_list = new;
		else
			end->next = new;
		end = new;
		lst = lst->next;
	}
	return (new_list);
}
