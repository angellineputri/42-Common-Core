/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_digit_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:13:55 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:45:43 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one_digit_sort(t_list *s, int digit)
{
	int	rotate;
	int	i;

	i = 0;
	rotate = 0;
	odmove_03(s, digit, i, rotate);
	ods_1(s, digit, i, rotate);
	odsort_03(s, digit, i, rotate);
}

void	odmove_03(t_list *s, int digit, int i, int rotate)
{
	int	size;

	size = s->size_a;
	while (i < size && search_num(s->a_arr, digit, '0', ' ')
		+ search_num(s->a_arr, digit, '3', ' '))
	{
		if (topa(s, digit, '0', ' ') || topa(s, digit, '3', ' '))
			pb(s, 1);
		else
		{
			ra(s, 1);
			rotate++;
		}
		i++;
	}
	ods_cleanup_a(s, i, size, rotate);
}

void	ods_1(t_list *s, int digit, int i, int rotate)
{
	int	size;

	size = s->size_a;
	while (i < size && search_num(s->a_arr, digit, '1', ' '))
	{
		if (topa(s, digit, '1', ' '))
			pb(s, 1);
		else
		{
			ra(s, 1);
			rotate++;
		}
		i++;
	}
	ods_cleanup_a(s, i, size, rotate);
	while (topb(s, digit, '1', ' '))
		pa(s, 1);
}

void	odsort_03(t_list *s, int digit, int i, int rotate)
{
	int	size;

	size = s->size_b;
	while (i < size && search_num(s->b_arr, digit, '0', ' '))
	{
		if (topb(s, digit, '0', ' '))
			pa(s, 1);
		else
		{
			rb(s, 1);
			rotate++;
		}
	}
	ods_cleanup_b(s, i, size, rotate);
	while (s->size_b)
		pa(s, 1);
	while (topa(s, digit, '3', ' '))
		ra(s, 1);
}
