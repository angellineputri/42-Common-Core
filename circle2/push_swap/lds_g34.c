/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lds_g34.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:40:17 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:45:24 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ld_sort_g4(t_list *s, int d, int q)
{
	while (s->size_a - search_num(s->a_arr, d, '2', '3') != 0)
	{
		if (topa(s, d, '2', '2') || topa(s, d, '3', '0'))
		{
			while (q > 0 && q--)
				rb(s, 1);
			pb(s, 1);
		}
		else if (topa(s, d, '2', '1'))
		{
			pb(s, 1);
			if ((s->b_arr[q + 1][d] == '2' && s->b_arr[q + 1][d + 1] == '2')
				|| (s->b_arr[q + 1][d] == '3' && s->b_arr[q + 1][d + 1] == '0'))
				q++;
		}
		else
		{
			if (q > 0 && q--)
				rr(s, 1);
			else
				ra(s, 1);
		}
	}
	q = ld_sort_21_22_30(s, d, q);
	return (q);
}

int	ld_sort_21_22_30(t_list *s, int digit, int rbq)
{
	while (rbq)
	{
		rb(s, 1);
		rbq--;
	}
	while (search_num(s->b_arr, digit, '2', '1')
		+ search_num(s->b_arr, digit, '2', '2')
		+ search_num(s->b_arr, digit, '3', '0'))
	{
		if (topb(s, digit, '2', '2'))
			pa(s, 1);
		else if (topb(s, digit, '3', '0'))
		{
			pa(s, 1);
			ra(s, 1);
		}
		else
		{
			if (topb(s, digit, '2', '1'))
				pa(s, 1);
			else if (botb(s, digit, '2', '1'))
				rrb(s, 1);
		}
	}
	return (rbq);
}

void	ld_sort_g3(t_list *s, int digit)
{
	int	i;
	int	top;

	i = 0;
	top = 0;
	while (search_num(s->b_arr, digit, '2', '0')
		+ search_num(s->b_arr, digit, '3', '1'))
	{
		if (topb(s, digit, '2', '0'))
			pa(s, 1);
		else if (topb(s, digit, '3', '1'))
		{
			pa(s, 1);
			ra(s, 1);
		}
	}
	while ((s->b_arr[i][digit] == '1' && s->b_arr[i][digit + 1] == '2')
			|| (s->b_arr[i][digit] == '1' && s->b_arr[i][digit + 1] == '3'))
	{
		if (s->b_arr[i][digit] == '1' && s->b_arr[i][digit + 1] == '3')
			top++;
		i++;
	}
	ld_sort_12_13(s, digit, top);
}

void	ld_sort_12_13(t_list *s, int digit, int top)
{
	while (search_num(s->b_arr, digit, '1', '2')
		+ search_num(s->b_arr, digit, '1', '3'))
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
		if (top > 0 && topb(s, digit, '1', '3') && top--)
			pa(s, 1);
		else if (top)
			rb(s, 1);
		if (!top && topb(s, digit, '1', '3'))
			pa(s, 1);
		else if (!top && (botb(s, digit, '1', '2') || botb(s, digit, '1', '3')))
			rrb(s, 1);
		if (!top && !search_num(s->b_arr, digit, '1', '3')
			&& topb(s, digit, '1', '2'))
			pa(s, 1);
	}
}
