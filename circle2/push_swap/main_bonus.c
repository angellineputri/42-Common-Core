/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:31:27 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 14:40:32 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "gnl_bonus.h"

int	check_inst(t_list *s, char *inst)
{
	if (!ft_strcmp(inst, "sa\n"))
		sa(s, 0);
	else if (!ft_strcmp(inst, "sb\n"))
		sb(s, 0);
	else if (!ft_strcmp(inst, "ss\n"))
		ss(s, 0);
	else if (!ft_strcmp(inst, "pa\n"))
		pa(s, 0);
	else if (!ft_strcmp(inst, "pb\n"))
		pb(s, 0);
	else if (!ft_strcmp(inst, "ra\n"))
		ra(s, 0);
	else if (!ft_strcmp(inst, "rb\n"))
		rb(s, 0);
	else if (!ft_strcmp(inst, "rr\n"))
		rr(s, 0);
	else if (!ft_strcmp(inst, "rra\n"))
		rra(s, 0);
	else if (!ft_strcmp(inst, "rrb\n"))
		rrb(s, 0);
	else if (!ft_strcmp(inst, "rrr\n"))
		rrr(s, 0);
	else
		return (0);
	return (1);
}

int	checker(t_list *s)
{
	char	*inst;

	inst = get_next_line(0);
	while (inst)
	{
		if (!check_inst(s, inst))
			return (free(inst), 0);
		else
		{
			free(inst);
			inst = get_next_line(0);
		}
	}
	free(inst);
	if (check_sorted(s))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	stacks;

	if (argc > 1)
	{
		stacks = struct_setup(argc - 1);
		if (!fill_struct(argv, &stacks))
		{
			return (done(&stacks, 1), -1);
		}
		if (checker(&stacks))
			return (done(&stacks, 0), 0);
		else
			return (done(&stacks, 1), -1);
	}
	else
		return (-1);
}
