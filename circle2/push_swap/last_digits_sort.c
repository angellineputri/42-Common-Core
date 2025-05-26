/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_digits_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:42:27 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 15:12:22 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_digits_sort(t_list *s, int digit)
{
	int	rbq;

	rbq = 0;
	rbq = ld_move_g123(s, digit, rbq);
	rbq = ld_sort_g4(s, digit, rbq);
	ld_sort_g3(s, digit);
	ld_sort_g2(s, digit);
	ld_sort_g1(s, digit);
}

int	ld_move_g123(t_list *s, int digit, int rbq)
{
	rbq = ld_move_g12(s, digit, rbq);
	while (rbq)
	{
		if (is_group4(s->a_arr[0], digit))
			rr(s, 1);
		else
			rb(s, 1);
		rbq--;
	}
	rbq = ld_move_g3(s, digit, rbq);
	while (rbq)
	{
		if (topa(s, digit, '2', '3'))
			rr(s, 1);
		else
			rb(s, 1);
		rbq--;
	}
	return (rbq);
}

int	ld_move_g12(t_list *s, int digit, int rbq)
{
	while (search_group1(s->a_arr, digit) + search_group2(s->a_arr, digit))
	{
		if (is_group2(s->a_arr[0], digit))
		{
			while (rbq > 0 && rbq--)
				rb(s, 1);
			pb(s, 1);
		}
		else if (is_group1(s->a_arr[0], digit))
		{
			pb(s, 1);
			if (search_group2(s->b_arr, digit))
				rbq++;
		}
		else
		{
			if (rbq > 0 && rbq--)
				rr(s, 1);
			else
				ra(s, 1);
		}
	}
	return (rbq);
}

int	ld_move_g3(t_list *s, int d, int rbq)
{
	while (search_group3(s->a_arr, d))
	{
		if (topa(s, d, '2', '0') || topa(s, d, '3', '1'))
		{
			while (rbq > 0 && rbq--)
				rb(s, 1);
			pb(s, 1);
		}
		else if (topa(s, d, '1', '2') || topa(s, d, '1', '3'))
		{
			pb(s, 1);
			if ((s->b_arr[rbq + 1][d] == '2' && s->b_arr[rbq + 1][d + 1] == '0')
				|| (s->b_arr[rbq + 1][d] == '3'
				&& s->b_arr[rbq + 1][d + 1] == '1'))
				rbq++;
		}
		else
		{
			if (rbq > 0 && rbq--)
				rr(s, 1);
			else
				ra(s, 1);
		}
	}
	return (rbq);
}
