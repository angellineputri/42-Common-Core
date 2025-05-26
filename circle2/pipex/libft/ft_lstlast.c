/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:44:57 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/21 14:48:06 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

/*
int     main()
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

        l->content = "hi1";
        l->next = l2;

        l2->content = "hi2";
        l2->next = l3;

        l3->content = "hi3";
        l3->next = l4;

        l4->content = "hi4";
        l4->next = NULL;

        printf("last: %s", (char *)ft_lstlast(l)->content);
}
*/
