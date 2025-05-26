/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:49:55 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/23 16:57:33 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_num(char **s, int digit, char a, char b)
{
	int	i;
	int	amt;

	i = 0;
	amt = 0;
	while (s && s[i])
	{
		if (a != ' ' && b == ' ' && s[i][digit] == a)
			amt++;
		if (a == ' ' && b != ' ' && s[i][digit + 1] == b)
			amt++;
		if (a != ' ' && b != ' ' && s[i][digit] == a && s[i][digit + 1] == b)
			amt++;
		i++;
	}
	return (amt);
}

int	topa(t_list *s, int digit, char a, char b)
{
	if (!s->a_arr)
		return (0);
	if (a != ' ' && b == ' ' && s->a_arr[0][digit] == a)
		return (1);
	if (a == ' ' && b != ' ' && s->a_arr[0][digit + 1] == b)
		return (1);
	if (a != ' ' && b != ' ' && s->a_arr[0][digit] == a
		&& s->a_arr[0][digit + 1] == b)
		return (1);
	return (0);
}

int	bota(t_list *s, int digit, char a, char b)
{
	if (!s->a_arr)
		return (0);
	if (a != ' ' && b == ' ' && s->a_arr[s->size_a - 1][digit] == a)
		return (1);
	if (a == ' ' && b != ' ' && s->a_arr[s->size_a - 1][digit + 1] == b)
		return (1);
	if (a != ' ' && b != ' ' && s->a_arr[s->size_a - 1][digit] == a
		&& s->a_arr[s->size_a - 1][digit + 1] == b)
		return (1);
	return (0);
}

int	topb(t_list *s, int digit, char a, char b)
{
	if (!s->b_arr)
		return (0);
	if (a != ' ' && b == ' ' && s->b_arr[0][digit] == a)
		return (1);
	if (a == ' ' && b != ' ' && s->b_arr[0][digit + 1] == b)
		return (1);
	if (a != ' ' && b != ' ' && s->b_arr[0][digit] == a
		&& s->b_arr[0][digit + 1] == b)
		return (1);
	return (0);
}

int	botb(t_list *s, int digit, char a, char b)
{
	if (!s->b_arr)
		return (0);
	if (a != ' ' && b == ' ' && s->b_arr[s->size_b - 1][digit] == a)
		return (1);
	if (a == ' ' && b != ' ' && s->b_arr[s->size_b - 1][digit + 1] == b)
		return (1);
	if (a != ' ' && b != ' ' && s->b_arr[s->size_b - 1][digit] == a
		&& s->b_arr[s->size_b - 1][digit + 1] == b)
		return (1);
	return (0);
}
