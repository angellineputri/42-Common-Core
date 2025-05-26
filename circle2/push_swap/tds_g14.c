/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tds_g14.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:02:36 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:46:18 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	td_sort_g1(t_list *s, int digit, int i)
{
	int	size;

	size = s->size_b;
	while (i < size || search_num(s->b_arr, digit, '0', '2'))
	{
		if (botb(s, digit, '0', '2'))
		{
			rrb(s, 1);
			pa(s, 1);
		}
		else
			rrb(s, 1);
		i++;
	}
	td_sort_g1_33(s, digit, i, size);
	td_sort_g1_01(s, digit, i, size);
}

void	td_sort_g1_33(t_list *s, int digit, int i, int size)
{
	i = 0;
	size = s->size_b;
	while (i < size || search_num(s->b_arr, digit, '3', '3'))
	{
		if (botb(s, digit, '3', '3'))
		{
			rrb(s, 1);
			pa(s, 1);
		}
		else
			rrb(s, 1);
		i++;
	}
	while (topa(s, digit, '3', '3'))
		ra(s, 1);
}

void	td_sort_g1_01(t_list *s, int digit, int i, int size)
{
	i = 0;
	size = s->size_b;
	while (i < size || search_num(s->b_arr, digit, '0', '1'))
	{
		if (botb(s, digit, '0', '1'))
		{
			rrb(s, 1);
			pa(s, 1);
		}
		else
			rrb(s, 1);
		i++;
	}
	while (s->size_b)
	{
		while (i < size)
		{
			rrb(s, 1);
			i++;
		}
		rrb(s, 1);
		pa(s, 1);
	}
}

void	td_sort_g4(t_list *s, int digit, int rotate)
{
	td_sort_g4_22(s, digit, &rotate);
	while (search_num(s->b_arr, digit, '3', '0'))
	{
		while (rotate > 0 && rotate--)
			rrb(s, 1);
		pa(s, 1);
	}
	while (topa(s, digit, '3', '0'))
		ra(s, 1);
	while (search_num(s->b_arr, digit, '2', '1'))
	{
		if (topb(s, digit, '2', '1'))
			pa(s, 1);
		else if (botb(s, digit, '2', '1'))
			rrb(s, 1);
	}
}

void	td_sort_g4_22(t_list *s, int digit, int *rotate)
{
	while (search_num(s->b_arr, digit, '2', '2'))
	{
		while (search_num(s->b_arr, digit, '2', '2') == 1)
		{
			if (topb(s, digit, '2', '2'))
				break ;
			else if (s->b_arr[1][digit] == '2' && s->b_arr[1][digit + 1] == '2')
				sb(s, 1);
			else
			{
				rb(s, 1);
				(*rotate)++;
			}
		}
		if (topb(s, digit, '2', '2'))
			pa(s, 1);
		else if (topb(s, digit, '3', '0'))
		{
			rb(s, 1);
			(*rotate)++;
		}
	}
}
