/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:33:55 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 14:54:44 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *stacks, int print)
{
	int		i;
	char	*temp;

	temp = stacks->a_arr[0];
	i = 1;
	while (i < stacks->size_a)
	{
		stacks->a_arr[i - 1] = stacks->a_arr[i];
		i++;
	}
	stacks->a_arr[i - 1] = temp;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list *stacks, int print)
{
	int		i;
	char	*temp;

	temp = stacks->b_arr[0];
	i = 1;
	while (i < stacks->size_b)
	{
		stacks->b_arr[i - 1] = stacks->b_arr[i];
		i++;
	}
	stacks->b_arr[i - 1] = temp;
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list *stacks, int print)
{
	int		i;
	char	*temp;

	temp = stacks->a_arr[0];
	i = 1;
	while (i < stacks->size_a)
	{
		stacks->a_arr[i - 1] = stacks->a_arr[i];
		i++;
	}
	stacks->a_arr[i - 1] = temp;
	temp = stacks->b_arr[0];
	i = 1;
	while (i < stacks->size_b)
	{
		stacks->b_arr[i - 1] = stacks->b_arr[i];
		i++;
	}
	stacks->b_arr[i - 1] = temp;
	if (print == 1)
		write(1, "rr\n", 3);
}
