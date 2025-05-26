/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:22:26 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 14:56:36 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	struct_setup(int size_a)
{
	t_list	stacks;

	stacks.a_num = NULL;
	stacks.a_arr = NULL;
	stacks.b_arr = NULL;
	stacks.size_a = size_a;
	stacks.size_b = 0;
	return (stacks);
}

int	fill_struct(char **argv, t_list *s)
{
	s->a_num = fill_initial(argv, s);
	if (!s->a_num)
		return (0);
	if (!change_numbers(s))
		return (0);
	s->a_arr = convert_to_quaternary(s);
	if (!s->a_arr)
		return (0);
	s->b_arr = fill_stackb(s);
	if (!s->b_arr)
		return (0);
	return (1);
}

void	done(t_list *stacks, int error)
{
	int	i;

	if (stacks->a_num)
		free(stacks->a_num);
	if (stacks->a_arr)
	{
		i = 0;
		while (stacks->a_arr[i])
			free(stacks->a_arr[i++]);
		free(stacks->a_arr);
	}
	if (stacks->b_arr)
	{
		i = 0;
		while (stacks->b_arr[i])
			free(stacks->b_arr[i++]);
		free(stacks->b_arr);
	}
	if (error == 1)
		write(1, "Error\n", 6);
}
