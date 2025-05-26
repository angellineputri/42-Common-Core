/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:29:00 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/21 13:41:54 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int main()
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (0);

	list->content = "list";
	list->next = NULL;
	
	t_list	*new;
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = "new";
	new->next = NULL;

	ft_lstadd_front(&list, new);
	
	printf("list content:\n");
	t_list *current;

	current = list;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
}
*/
