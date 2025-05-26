/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:49:45 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/23 13:53:55 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_group1(char **stack, int digit)
{
	int	i;
	int	amt;

	i = 0;
	amt = 0;
	while (stack[i])
	{
		if (is_group1(stack[i], digit))
			amt++;
		i++;
	}
	return (amt);
}

int	search_group2(char **stack, int digit)
{
	int	i;
	int	amt;

	i = 0;
	amt = 0;
	while (stack[i])
	{
		if (is_group2(stack[i], digit))
			amt++;
		i++;
	}
	return (amt);
}

int	search_group3(char **stack, int digit)
{
	int	i;
	int	amt;

	i = 0;
	amt = 0;
	while (stack[i])
	{
		if (is_group3(stack[i], digit))
			amt++;
		i++;
	}
	return (amt);
}

int	search_group4(char **stack, int digit)
{
	int	i;
	int	amt;

	i = 0;
	amt = 0;
	while (stack[i])
	{
		if (is_group4(stack[i], digit))
			amt++;
		i++;
	}
	return (amt);
}
