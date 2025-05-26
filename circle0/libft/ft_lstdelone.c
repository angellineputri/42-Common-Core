/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:51:21 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/21 14:24:03 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	del(void *content)
{
	free(content);
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(del)(lst->content);
	free(lst);
}
