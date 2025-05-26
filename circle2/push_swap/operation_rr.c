/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:34:03 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 14:55:04 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *stacks, int print)
{
	int		i;
	char	*temp;

	i = stacks->size_a - 1;
	temp = stacks->a_arr[i];
	while (i > 0)
	{
		stacks->a_arr[i] = stacks->a_arr[i - 1];
		i--;
	}
	stacks->a_arr[i] = temp;
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list *stacks, int print)
{
	int		i;
	char	*temp;

	i = stacks->size_b - 1;
	temp = stacks->b_arr[i];
	while (i > 0)
	{
		stacks->b_arr[i] = stacks->b_arr[i - 1];
		i--;
	}
	stacks->b_arr[i] = temp;
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list *stacks, int print)
{
	int		i;
	char	*temp;

	i = stacks->size_a - 1;
	temp = stacks->a_arr[i];
	while (i > 0)
	{
		stacks->a_arr[i] = stacks->a_arr[i - 1];
		i--;
	}
	stacks->a_arr[i] = temp;
	i = stacks->size_b - 2;
	temp = stacks->b_arr[i];
	while (i > 0)
	{
		stacks->b_arr[i] = stacks->b_arr[i - 1];
		i--;
	}
	stacks->b_arr[i] = temp;
	if (print == 1)
		write(1, "rrr\n", 4);
}
