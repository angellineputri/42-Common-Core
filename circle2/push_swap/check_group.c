/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:40:30 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/23 13:40:58 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_group1(char *num, int digit)
{
	if (num[digit] == '0' && num[digit + 1] == '0')
		return (1);
	else if (num[digit] == '0' && num[digit + 1] == '1')
		return (1);
	else if (num[digit] == '0' && num[digit + 1] == '2')
		return (1);
	else if (num[digit] == '3' && num[digit + 1] == '3')
		return (1);
	return (0);
}

int	is_group2(char *num, int digit)
{
	if (num[digit] == '0' && num[digit + 1] == '3')
		return (1);
	else if (num[digit] == '1' && num[digit + 1] == '0')
		return (1);
	else if (num[digit] == '1' && num[digit + 1] == '1')
		return (1);
	else if (num[digit] == '3' && num[digit + 1] == '2')
		return (1);
	return (0);
}

int	is_group3(char *num, int digit)
{
	if (num[digit] == '1' && num[digit + 1] == '2')
		return (1);
	else if (num[digit] == '1' && num[digit + 1] == '3')
		return (1);
	else if (num[digit] == '2' && num[digit + 1] == '0')
		return (1);
	else if (num[digit] == '3' && num[digit + 1] == '1')
		return (1);
	return (0);
}

int	is_group4(char *num, int digit)
{
	if (num[digit] == '2' && num[digit + 1] == '1')
		return (1);
	else if (num[digit] == '2' && num[digit + 1] == '2')
		return (1);
	else if (num[digit] == '2' && num[digit + 1] == '3')
		return (1);
	else if (num[digit] == '3' && num[digit + 1] == '0')
		return (1);
	return (0);
}

int	half(t_list *s, int digit)
{
	int	i;

	i = 0;
	if (digit > 0)
		return (0);
	while (i < s->size_a)
	{
		if (s->a_arr[i][digit] == '2' || s->a_arr[i][digit] == '3')
			return (0);
		i++;
	}
	return (1);
}
