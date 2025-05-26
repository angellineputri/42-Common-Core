/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fh_last.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:26:22 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:44:31 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	firsthalf_last(t_list *s, int digit, int rotate)
{
	firsthalf_last_10(s, digit, &rotate);
	firsthalf_last_1100_part1(s, digit, &rotate);
	firsthalf_last_1100_part2(s, digit, &rotate);
}

void	firsthalf_last_10(t_list *s, int digit, int *rotate)
{
	while (search_num(s->b_arr, digit, '1', '0'))
	{
		if (topb(s, digit, '1', '0'))
		{
			pa(s, 1);
			if (search_num(s->b_arr, digit, '1', '0')
				&& !topb(s, digit, '1', '0'))
			{
				rr(s, 1);
				(*rotate)++;
			}
			else
				ra(s, 1);
		}
		else
		{
			rb(s, 1);
			(*rotate)++;
		}
	}
}

void	firsthalf_last_1213(t_list *s, int digit, int *rotate)
{
	(*rotate) = 0;
	while (search_num(s->b_arr, digit, '1', '3'))
	{
		if (topb(s, digit, '1', '3'))
			pa(s, 1);
		else if (topb(s, digit, '1', '2'))
		{
			rb(s, 1);
			(*rotate)++;
		}
	}
	while ((*rotate)--)
		rrb(s, 1);
	while (search_num(s->b_arr, digit, '1', '2'))
	{
		if (topb(s, digit, '1', '2'))
			pa(s, 1);
	}
}

void	firsthalf_last_1100_part1(t_list *s, int digit, int *rotate)
{
	if (search_num(s->b_arr, digit, '1', '1') - (*rotate) < (*rotate))
	{
		while (topb(s, digit, '1', '1'))
			rb(s, 1);
	}
	else
	{
		while (botb(s, digit, '1', '1'))
			rrb(s, 1);
		while (topb(s, digit, '1', '1'))
		{
			pa(s, 1);
			ra(s, 1);
		}
	}
	if (search_num(s->b_arr, digit, '0', '0'))
	{
		while ((topb(s, digit, '1', '2') || topb(s, digit, '1', '3')))
			rb(s, 1);
		while (topb(s, digit, '0', '0'))
			pa(s, 1);
	}
	else
		firsthalf_last_1213(s, digit, rotate);
}

void	firsthalf_last_1100_part2(t_list *s, int digit, int *rotate)
{
	while (topb(s, digit, '1', '1'))
	{
		pa(s, 1);
		ra(s, 1);
	}
	if (s->size_b == 0)
	{
		while (!topa(s, digit, '0', '0'))
			ra(s, 1);
	}
	else
	{
		firsthalf_last_1213(s, digit, rotate);
		while (!topa(s, digit, '0', '0'))
			ra(s, 1);
	}
}
