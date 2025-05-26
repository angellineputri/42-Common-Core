/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:42:42 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/21 14:43:42 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*current;

	len = 0;
	current = lst;
	if (!lst)
		return (0);
	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	return (len);
}

/*
int	main()
{
	t_list *l;
	t_list *l2;
	t_list *l3;
	t_list *l4;

	l = malloc(sizeof(t_list));
	if (!l)
		return (0);
	l2 = malloc(sizeof(t_list));
	if (!l2)
		return (0);
	l3 = malloc(sizeof(t_list));
	if (!l3)
		return (0);
	l4 = malloc(sizeof(t_list));
	if (!l4)
		return (0);
	
	l->content = "hi";
	l->next = l2;

	l2->content = "hi";
        l2->next = l3;
        
	l3->content = "hi";
        l3->next = l4;
        
	l4->content = "hi";
        l4->next = NULL;

	printf("len: %d", ft_lstsize(l));
}
*/
