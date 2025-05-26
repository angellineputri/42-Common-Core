/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:34:51 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 15:10:06 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	basecase_3(t_list *stacks)
{
	char	**s;

	s = stacks->a_arr;
	if (ft_atoi(s[0]) < ft_atoi(s[1]) && ft_atoi(s[0]) < ft_atoi(s[2])
		&& ft_atoi(s[2]) < ft_atoi(s[1]))
	{
		sa(stacks, 1);
		ra(stacks, 1);
	}
	else if (ft_atoi(s[1]) < ft_atoi(s[0]) && ft_atoi(s[1]) < ft_atoi(s[2])
		&& ft_atoi(s[0]) < ft_atoi(s[2]))
		sa(stacks, 1);
	else if (ft_atoi(s[1]) < ft_atoi(s[0]) && ft_atoi(s[1]) < ft_atoi(s[2])
		&& ft_atoi(s[2]) < ft_atoi(s[0]))
		ra(stacks, 1);
	else if (ft_atoi(s[2]) < ft_atoi(s[0]) && ft_atoi(s[2]) < ft_atoi(s[1])
		&& ft_atoi(s[0]) < ft_atoi(s[1]))
		rra(stacks, 1);
	else if (ft_atoi(s[2]) < ft_atoi(s[0]) && ft_atoi(s[2]) < ft_atoi(s[1])
		&& ft_atoi(s[1]) < ft_atoi(s[0]))
	{
		sa(stacks, 1);
		rra(stacks, 1);
	}
}

void	basecase_4(t_list *stacks)
{
	char	**s;

	s = stacks->a_arr;
	if (ft_atoi(s[0]) == 0 && !(ft_atoi(s[1]) == 1
			&& ft_atoi(s[2]) == 2 && ft_atoi(s[3]) == 3))
	{
		pb(stacks, 1);
		basecase_3(stacks);
		pa(stacks, 1);
	}
	else if (ft_atoi(s[0]) == 1)
		basecase_4_1(stacks);
	else if (ft_atoi(s[0]) == 2)
	{
		ra(stacks, 1);
		basecase_4(stacks);
	}
	else if (ft_atoi(s[0]) == 3)
	{
		pb(stacks, 1);
		basecase_3(stacks);
		pa(stacks, 1);
		ra(stacks, 1);
	}
}

void	basecase_4_1(t_list *stacks)
{
	char	**s;

	s = stacks->a_arr;
	if (!(ft_atoi(s[1]) == 0 && ft_atoi(s[2]) == 2 && ft_atoi(s[3]) == 3))
	{
		pb(stacks, 1);
		basecase_3(stacks);
		pa(stacks, 1);
	}
	sa(stacks, 1);
}

void	basecase_56(t_list *stacks)
{
	while (search_num(stacks->a_arr, 0, '1', ' '))
	{
		if (bota(stacks, 0, '1', '0') || bota(stacks, 0, '1', '1'))
			rra(stacks, 1);
		else if (topa(stacks, 0, '1', '0') || topa(stacks, 0, '1', '1'))
			pb(stacks, 1);
		else
			ra(stacks, 1);
	}
	basecase_4(stacks);
	while (stacks->size_b)
		pa(stacks, 1);
	if (topa(stacks, 0, '1', '1'))
		sa(stacks, 1);
	if (topa(stacks, 0, '1', '0'))
		ra(stacks, 1);
	if (topa(stacks, 0, '1', '1'))
		ra(stacks, 1);
}
