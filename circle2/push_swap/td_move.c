/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   td_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:55:00 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:46:02 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	td_move_all(t_list *s, int digit, int i, int rotate)
{
	int	size;

	size = s->size_a;
	while (i < size && s->size_a - search_num(s->a_arr, digit, '2', ' ')
		- search_num(s->a_arr, digit, '1', '2')
		- search_num(s->a_arr, digit, '1', '3')
		- search_num(s->a_arr, digit, '3', '1')
		- search_num(s->a_arr, digit, '3', '0'))
	{
		rotate += td_move_g12(s, digit, &i, size);
		i++;
	}
	td_cleanup(s, &i, &size, &rotate);
	while (i < size && s->size_a - search_num(s->a_arr, digit, '2', ' ')
		+ search_num(s->a_arr, digit, '2', '0')
		- search_num(s->a_arr, digit, '3', '0'))
	{
		rotate += td_move_g3(s, digit, &i, size);
		i++;
	}
	td_cleanup(s, &i, &size, &rotate);
	while (i < size && s->size_a - search_num(s->a_arr, digit, '2', '3') != 0)
		rotate += td_move_g4(s, digit, &i, size);
	td_cleanup(s, &i, &size, &rotate);
}

int	td_move_g12(t_list *s, int digit, int *i, int size)
{
	if (is_group2(s->a_arr[0], digit))
		return (pb(s, 1), 0);
	else if (is_group1(s->a_arr[0], digit))
	{
		pb(s, 1);
		if (s->size_b - search_num(s->b_arr, digit, '0', ' ')
			+ search_num(s->b_arr, digit, '0', '3')
			- search_num(s->b_arr, digit, '3', '3') != 0)
		{
			if ((*i) < size - 1 && !is_group2(s->a_arr[0], digit)
				&& !is_group1(s->a_arr[0], digit))
			{
				rr(s, 1);
				return ((*i)++, 1);
			}
			else
				return (rb(s, 1), 0);
		}
		return (0);
	}
	else
		return (ra(s, 1), 1);
}

int	td_move_g3(t_list *s, int digit, int *i, int size)
{
	if (topa(s, digit, '2', '0') || topa(s, digit, '3', '1'))
		return (pb(s, 1), 0);
	else if (topa(s, digit, '1', '2') || topa(s, digit, '1', '3'))
	{
		pb(s, 1);
		if ((*i) < size - 1 && !(topa(s, digit, '2', '0')
				||topa(s, digit, '3', '1') || topa(s, digit, '1', '2')
				|| topa(s, digit, '1', '3')))
		{
			rr(s, 1);
			(*i)++;
			return (1);
		}
		else
			return (rb(s, 1), 0);
	}
	else
	{
		ra(s, 1);
		return (1);
	}
}

int	td_move_g4(t_list *s, int digit, int *i, int size)
{
	if (topa(s, digit, '2', '2') || topa(s, digit, '3', '0'))
		return (pb(s, 1), (*i)++, 0);
	else if (topa(s, digit, '2', '1'))
	{
		pb(s, 1);
		if ((*i) < size - 1 && !(topa(s, digit, '2', '2')
				|| topa(s, digit, '3', '0') || topa(s, digit, '2', '1')))
		{
			rr(s, 1);
			(*i) += 2;
			return (1);
		}
		else
		{
			rb(s, 1);
			return ((*i)++, 0);
		}
	}
	else
	{
		ra(s, 1);
		return ((*i)++, 1);
	}
}
