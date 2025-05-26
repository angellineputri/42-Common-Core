/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fh_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:27:40 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:44:47 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	firsthalf_move012(t_list *s, int digit, int i, int rotate)
{
	int	size;

	size = s->size_a;
	while (i < size && search_num(s->a_arr, digit, ' ', '0')
		+ search_num(s->a_arr, digit, ' ', '1'))
	{
		rotate += firsthalf_move01(s, digit, &i, size);
		i++;
	}
	firsthalf_cleanup(s, i, size, rotate);
	i = 0;
	rotate = 0;
	size = s->size_a;
	while (i < size && s->size_a - search_num(s->a_arr, digit, '0', '3'))
	{
		if (firsthalf_move2(s, digit, &rotate) == 0)
			return ;
		i++;
	}
	firsthalf_cleanup(s, i, size, rotate);
}

int	firsthalf_move01(t_list *s, int digit, int *i, int size)
{
	if (topa(s, digit, '0', '0') || topa(s, digit, '0', '1'))
		return (pb(s, 1), 0);
	else if (topa(s, digit, '1', '0') || topa(s, digit, '1', '1'))
	{
		pb(s, 1);
		if (s->size_b > 1)
		{
			if ((*i) < size - 1 && !(topa(s, digit, '0', '0')
					|| topa(s, digit, '0', '1') || topa(s, digit, '1', '0')
					|| topa(s, digit, '1', '1')))
			{
				rr(s, 1);
				(*i)++;
				return (1);
			}
			else
				return (rb(s, 1), 0);
		}
		return (0);
	}
	else
	{
		ra(s, 1);
		return (1);
	}
}

int	firsthalf_move2(t_list *s, int digit, int *rotate)
{
	while (search_num(s->a_arr, digit, '0', '3') - (*rotate) == 1)
	{
		if (topa(s, digit, '0', '3'))
		{
			ra(s, 1);
			return (0);
		}
		else if (s->a_arr[1][digit] == '0' && s->a_arr[1][digit + 1] == '3')
			sa(s, 1);
		else
			pb(s, 1);
	}
	if (topa(s, digit, ' ', '2') || topa(s, digit, '1', '3'))
		pb(s, 1);
	else if (topa(s, digit, '0', '3'))
	{
		ra(s, 1);
		(*rotate)++;
	}
	return (1);
}

void	firsthalf_cleanup(t_list *s, int i, int size, int rotate)
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
