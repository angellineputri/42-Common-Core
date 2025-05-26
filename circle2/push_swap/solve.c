/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:38:15 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:43:03 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list *s)
{
	int	i;
	int	j;
	int	digit;

	i = 1;
	digit = quaternary_len(s->size_a - 1);
	if (s->size_b)
		return (0);
	while (i < s->size_a)
	{
		j = 0;
		while (j < digit)
		{
			if (s->a_arr[i][j] == s->a_arr[i - 1][j])
				j++;
			else if (s->a_arr[i][j] < s->a_arr[i - 1][j])
				return (0);
			else
				break ;
		}
		i++;
	}
	return (1);
}

void	push_swap(t_list *s)
{
	if (check_sorted(s))
		return ;
	else if (s->size_a == 2 && s->a_num[0] > s->a_num[1])
		sa(s, 1);
	else if (s->size_a == 3)
		basecase_3(s);
	else if (s->size_a == 4)
		basecase_4(s);
	else if (s->size_a == 5 || s->size_a == 6)
		basecase_56(s);
	else
		radix(s);
}

void	radix(t_list *s)
{
	int	digit;

	digit = quaternary_len(s->size_a - 1) - 2;
	last_digits_sort(s, digit);
	if (digit % 2 == 1)
	{
		digit--;
		one_digit_sort(s, digit);
	}
	digit -= 2;
	while (digit > 0)
	{
		two_digits_sort(s, digit);
		digit -= 2;
	}
	if (digit == 0)
	{
		if (half(s, digit) == 1)
		{
			first_two_digits_half(s, digit);
		}
		else
			two_digits_sort(s, digit);
	}
}
