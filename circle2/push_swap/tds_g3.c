/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tds_g3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:01:12 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:46:08 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	td_sort_g3(t_list *s, int digit, int i)
{
	int	top;

	top = 0;
	td_sort_g3_2031(s, digit);
	while ((s->b_arr[i][digit] == '1' && s->b_arr[i][digit + 1] == '2')
		|| (s->b_arr[i][digit] == '1' && s->b_arr[i][digit + 1] == '3'))
	{
		if (s->b_arr[i][digit] == '1' && s->b_arr[i][digit + 1] == '3')
			top++;
		i++;
	}
	i = 0;
	while (search_num(s->b_arr, digit, '1', '3'))
	{
		td_sort_g3_13(s, digit, top);
		if (botb(s, digit, '1', '3'))
			rrb(s, 1);
		else if (botb(s, digit, '1', '2'))
		{
			rrb(s, 1);
			i++;
		}
	}
	td_sort_g3_12(s, digit, i);
}

void	td_sort_g3_2031(t_list *s, int digit)
{
	while (search_num(s->b_arr, digit, '2', '0'))
	{
		if (topb(s, digit, '2', '0'))
			pa(s, 1);
		else if (topb(s, digit, '3', '1'))
			rb(s, 1);
	}
	while (search_num(s->b_arr, digit, '3', '1'))
	{
		while (botb(s, digit, '3', '1'))
			rrb(s, 1);
		while (topb(s, digit, '3', '1'))
			pa(s, 1);
	}
	while (topa(s, digit, '3', '1'))
		ra(s, 1);
}

void	td_sort_g3_13(t_list *s, int digit, int top)
{
	while (top)
	{
		while (top == 1)
		{
			if (topb(s, digit, '1', '3'))
				break ;
			else if (s->b_arr[1][digit] == '1' && s->b_arr[1][digit + 1] == '3')
				sb(s, 1);
			else
				rb(s, 1);
		}
		if (topb(s, digit, '1', '3'))
		{
			pa(s, 1);
			top--;
		}
		else
			rb(s, 1);
	}
	if (topb(s, digit, '1', '3'))
		pa(s, 1);
}

void	td_sort_g3_12(t_list *s, int digit, int i)
{
	while (search_num(s->b_arr, digit, '1', '2'))
	{
		while (i > 2)
		{
			rb(s, 1);
			i--;
		}
		if (i == 2)
		{
			sb(s, 1);
			pa(s, 1);
			pa(s, 1);
			i -= 2;
		}
		rrb(s, 1);
		pa(s, 1);
	}
}
