/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_half.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:45:40 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:44:57 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_two_digits_half(t_list *s, int digit)
{
	int	i;
	int	rotate;

	i = 0;
	rotate = 0;
	firsthalf_move012(s, digit, i, rotate);
	firsthalf_sort2(s, digit);
	firsthalf_sort01(s, digit, rotate);
	firsthalf_last(s, digit, rotate);
}

void	firsthalf_sort2(t_list *s, int digit)
{
	while (search_num(s->a_arr, digit, '1', '2'))
	{
		while (search_num(s->a_arr, digit, '1', '2') == 1)
		{
			if (topa(s, digit, '1', '2'))
				break ;
			else if (s->a_arr[1][digit] == '1' && s->a_arr[1][digit + 1] == '2')
				sa(s, 1);
			else
				pb(s, 1);
		}
		pb(s, 1);
	}
	while (search_num(s->b_arr, digit, '0', '2'))
	{
		if (topb(s, digit, '0', '2'))
			pa(s, 1);
		else
			rb(s, 1);
	}
	while (topb(s, digit, '1', '2') || topb(s, digit, '1', '3'))
		rb(s, 1);
}

void	firsthalf_sort01(t_list *s, int digit, int rotate)
{
	while (search_num(s->b_arr, digit, '0', '1'))
	{
		if (topb(s, digit, '0', '0'))
		{
			rb(s, 1);
			rotate++;
		}
		else if (topb(s, digit, '0', '1'))
			pa(s, 1);
	}
	if (search_num(s->b_arr, digit, '0', '0') - rotate < rotate
		|| rotate > search_num(s->b_arr, digit, '0', '0') - rotate
		+ search_num(s->b_arr, digit, '1', '2')
		+ search_num(s->b_arr, digit, '1', '3'))
	{
		while (topb(s, digit, '0', '0'))
			rb(s, 1);
	}
	else
	{
		while (rotate--)
			rrb(s, 1);
		while (topb(s, digit, '0', '0'))
			pa(s, 1);
	}
}
