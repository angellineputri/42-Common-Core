/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lds_g12.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:39:08 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:45:14 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ld_sort_g2(t_list *s, int digit)
{
	int	i;
	int	top;

	ld_sort_11_32(s, digit);
	i = 0;
	top = 0;
	while ((s->b_arr[i][digit] == '1' && s->b_arr[i][digit + 1] == '0')
		|| (s->b_arr[i][digit] == '0' && s->b_arr[i][digit + 1] == '3'))
	{
		if (s->b_arr[i][digit] == '1' && s->b_arr[i][digit + 1] == '0')
			top++;
		i++;
	}
	while (search_num(s->b_arr, digit, '0', '3')
		+ search_num(s->b_arr, digit, '1', '0'))
	{
		ld_sort_03_10(s, digit, &top);
	}
}

void	ld_sort_11_32(t_list *s, int d)
{
	while (search_num(s->b_arr, d, '1', '1')
		+ search_num(s->b_arr, d, '3', '2'))
	{
		if (search_num(s->b_arr, d, '1', '1')
			+ search_num(s->b_arr, d, '3', '2') == 1
			&& ((s->b_arr[1][d] == '1' && s->b_arr[1][d + 1] == '1')
			|| (s->b_arr[1][d] == '3' && s->b_arr[1][d + 1] == '2')))
			sb(s, 1);
		if (topb(s, d, '1', '1'))
			pa(s, 1);
		else if (topb(s, d, '3', '2'))
		{
			pa(s, 1);
			ra(s, 1);
		}
		else
			rb(s, 1);
	}
}

void	ld_sort_03_10(t_list *s, int digit, int *top)
{
	while ((*top))
	{
		while ((*top) == 1)
		{
			if (topb(s, digit, '1', '0'))
				break ;
			else if (s->b_arr[1][digit] == '1' && s->b_arr[1][digit + 1] == '0')
				sb(s, 1);
			else
				rb(s, 1);
		}
		if (topb(s, digit, '1', '0'))
		{
			pa(s, 1);
			(*top)--;
		}
		else
			rb(s, 1);
	}
	if (topb(s, digit, '1', '0'))
		pa(s, 1);
	else if (botb(s, digit, '0', '3') || botb(s, digit, '1', '0'))
		rrb(s, 1);
	if (!search_num(s->b_arr, digit, '1', '0') && topb(s, digit, '0', '3'))
		pa(s, 1);
}

void	ld_sort_g1(t_list *s, int digit)
{
	int	raq;

	raq = 0;
	raq = ld_sort_02_33(s, digit, raq);
	while (search_num(s->b_arr, digit, '0', '1'))
	{
		if (topb(s, digit, '0', '1'))
		{
			while (raq > 0 && raq--)
				ra(s, 1);
			pa(s, 1);
		}
		else
		{
			if (raq > 0 && raq--)
				rr(s, 1);
			else
				rb(s, 1);
		}
	}
	while (s->size_b)
		pa(s, 1);
}

int	ld_sort_02_33(t_list *s, int digit, int raq)
{
	while (search_num(s->b_arr, digit, '0', '2')
		+ search_num(s->b_arr, digit, '3', '3'))
	{
		if (topb(s, digit, '0', '2'))
		{
			while (raq > 0 && raq--)
				ra(s, 1);
			pa(s, 1);
		}
		else if (topb(s, digit, '3', '3'))
		{
			pa(s, 1);
			raq++;
		}
		else
		{
			if (raq > 0 && raq--)
				rr(s, 1);
			else
				rb(s, 1);
		}
	}
	return (raq);
}
