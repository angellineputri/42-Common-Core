/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:26:41 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 14:22:42 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		push_swap(&stacks);
		return (done(&stacks, 0), 0);
	}
	else
		return (-1);
}
