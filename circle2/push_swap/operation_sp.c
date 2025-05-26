/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:34:11 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 14:55:32 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stacks, int print)
{
	char	*temp;

	temp = stacks->a_arr[0];
	stacks->a_arr[0] = stacks->a_arr[1];
	stacks->a_arr[1] = temp;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list *stacks, int print)
{
	char	*temp;

	temp = stacks->b_arr[0];
	stacks->b_arr[0] = stacks->b_arr[1];
	stacks->b_arr[1] = temp;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list *stacks, int print)
{
	char	*temp;

	temp = stacks->a_arr[0];
	stacks->a_arr[0] = stacks->a_arr[1];
	stacks->a_arr[1] = temp;
	temp = stacks->b_arr[0];
	stacks->b_arr[0] = stacks->b_arr[1];
	stacks->b_arr[1] = temp;
	if (print == 1)
		write(1, "ss\n", 3);
}

void	pa(t_list *stacks, int print)
{
	int		i;
	char	*temp;

	if (!stacks->size_b)
		return ;
	i = stacks->size_a;
	temp = stacks->a_arr[i];
	while (i > 0)
	{
		stacks->a_arr[i] = stacks->a_arr[i - 1];
		i--;
	}
	stacks->a_arr[i] = stacks->b_arr[i];
	while (i < stacks->size_b - 1)
	{
		stacks->b_arr[i] = stacks->b_arr[i + 1];
		i++;
	}
	stacks->b_arr[i] = temp;
	stacks->size_a += 1;
	stacks->size_b -= 1;
	if (print == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list *stacks, int print)
{
	int		i;
	char	*temp;

	if (!stacks->size_a)
		return ;
	i = stacks->size_b;
	temp = stacks->b_arr[i];
	while (i > 0)
	{
		stacks->b_arr[i] = stacks->b_arr[i - 1];
		i--;
	}
	stacks->b_arr[i] = stacks->a_arr[i];
	while (i < stacks->size_a - 1)
	{
		stacks->a_arr[i] = stacks->a_arr[i + 1];
		i++;
	}
	stacks->a_arr[i] = temp;
	stacks->size_b += 1;
	stacks->size_a -= 1;
	if (print == 1)
		write(1, "pb\n", 3);
}
