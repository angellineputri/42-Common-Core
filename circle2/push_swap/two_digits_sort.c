/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_digits_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:05:34 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:46:29 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_digits_sort(t_list *s, int digit)
{
	int	i;
	int	rotate;

	i = 0;
	rotate = 0;
	td_move_all(s, digit, i, rotate);
	td_sort_g4(s, digit, rotate);
	td_sort_g3(s, digit, i);
	td_sort_g2(s, digit, rotate);
	td_sort_g1(s, digit, i);
}

void	td_sort_g2(t_list *s, int digit, int rotate)
{
	while (search_num(s->b_arr, digit, '1', '1'))
	{
		while (search_num(s->b_arr, digit, '1', '1') == 1)
		{
			if (topb(s, digit, '1', '1'))
				break ;
			else if ((s->b_arr[1][digit] == '1'
				&& s->b_arr[1][digit + 1] == '1'))
				sb(s, 1);
			else
			{
				rb(s, 1);
				rotate++;
			}
		}
		if (topb(s, digit, '1', '1'))
			pa(s, 1);
		else
		{
			rb(s, 1);
			rotate++;
		}
	}
	td_sort_g2_32(s, digit, rotate);
	td_sort_g2_0310(s, digit, rotate);
}

void	td_sort_g2_32(t_list *s, int digit, int rotate)
{
	while (search_num(s->b_arr, digit, '3', '2'))
	{
		while (rotate > 0 && rotate--)
			rrb(s, 1);
		while (search_num(s->b_arr, digit, '3', '2') == 1)
		{
			if (topb(s, digit, '3', '2'))
				break ;
			else if ((s->b_arr[1][digit] == '3'
				&& s->b_arr[1][digit + 1] == '2'))
			{
				sb(s, 1);
				break ;
			}
			else
				rb(s, 1);
		}
		if (topb(s, digit, '3', '2'))
			pa(s, 1);
		else
			rb(s, 1);
	}
	while (topa(s, digit, '3', '2'))
		ra(s, 1);
}

void	td_sort_g2_0310(t_list *s, int digit, int rotate)
{
	rotate = 0;
	while (botb(s, digit, '0', '3') || botb(s, digit, '1', '0'))
		rrb(s, 1);
	while (search_num(s->b_arr, digit, '1', '0'))
	{
		if (topb(s, digit, '1', '0'))
			pa(s, 1);
		else
		{
			rb(s, 1);
			rotate++;
		}
	}
	while (search_num(s->b_arr, digit, '0', '3'))
	{
		while (rotate)
		{
			rrb(s, 1);
			rotate--;
		}
		if (topb(s, digit, '0', '3'))
			pa(s, 1);
		else
			rb(s, 1);
	}
}

void	td_cleanup(t_list *s, int *i, int *size, int *rotate)
{
	if ((*size) - (*i) < (*rotate))
	{
		while ((*i) < (*size))
		{
			ra(s, 1);
			(*i)++;
		}
	}
	else
	{
		while ((*rotate))
		{
			rra(s, 1);
			(*rotate)--;
		}
	}
	(*rotate) = 0;
	(*i) = 0;
	(*size) = s->size_a;
}
