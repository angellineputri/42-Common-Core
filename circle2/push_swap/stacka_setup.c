/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:55:12 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/23 12:42:02 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*fill_initial(char **argv, t_list *stacks)
{
	int	i;
	int	*stack;

	i = 1;
	stack = malloc(sizeof(int) * stacks->size_a);
	if (!stack)
		return (NULL);
	while (argv[i])
	{
		stack[i - 1] = ft_atoi(argv[i]);
		if (stack[i - 1] == 0 && argv[i][0] != '0')
			return (free(stack), NULL);
		i++;
	}
	if (check_duplicate(stack, stacks->size_a))
		return (free(stack), NULL);
	return (stack);
}

int	change_numbers(t_list *s)
{
	int	smallest;
	int	*filled;
	int	i;
	int	j;

	filled = malloc (sizeof(int) * s->size_a);
	if (!filled)
		return (0);
	i = 1;
	while (i <= s->size_a)
	{
		j = 0;
		smallest = -1;
		while (j < s->size_a)
		{
			if (!ft_strchr(filled, j, i)
				&& (smallest == -1 || (s->a_num[j] < s->a_num[smallest])))
				smallest = j;
			j++;
		}
		filled[i - 1] = smallest;
		s->a_num[smallest] = i - 1;
		i++;
	}
	return (free(filled), 1);
}

int	fill_quaternary(t_list *s, int max, char ***new_stack)
{
	int		i;
	int		j;
	char	*converted;
	int		temp;

	i = 0;
	while (i < s->size_a)
	{
		converted = malloc(sizeof(char) * (max + 1));
		if (!converted)
			return (i);
		j = 1;
		temp = s->a_num[i];
		while (j <= max)
		{
			converted[max - j] = (temp % 4) + '0';
			temp /= 4;
			j++;
		}
		converted[max] = '\0';
		(*new_stack)[i] = converted;
		i++;
	}
	(*new_stack)[i] = NULL;
	return (-1);
}

char	**convert_to_quaternary(t_list *s)
{
	int		i;
	int		max;
	int		indexerr;
	char	**new_stack;

	max = quaternary_len(s->size_a - 1);
	new_stack = malloc(sizeof(char *) * (s->size_a + 1));
	if (!new_stack)
		return (NULL);
	indexerr = fill_quaternary(s, max, &new_stack);
	if (indexerr != -1)
	{
		i = 0;
		while (i < indexerr)
		{
			free(new_stack[i]);
			i++;
		}
		return (free(new_stack), NULL);
	}
	return (new_stack);
}
