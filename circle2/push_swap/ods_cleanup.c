/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ods_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:36:19 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:45:38 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ods_cleanup_a(t_list *s, int i, int size, int rotate)
{
	if (size - i < rotate)
	{
		while (i < size)
		{
			ra(s, 1);
			i++;
		}
	}
	else
	{
		while (rotate)
		{
			rra(s, 1);
			rotate--;
		}
	}
}

void	ods_cleanup_b(t_list *s, int i, int size, int rotate)
{
	if (size - i < rotate)
	{
		while (i < size)
		{
			rb(s, 1);
			i++;
		}
	}
	else
	{
		while (rotate)
		{
			rrb(s, 1);
			rotate--;
		}
	}
}
