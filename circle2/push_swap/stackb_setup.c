/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackb_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:39:41 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/23 13:14:28 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**fill_stackb(t_list *s)
{
	int		i;
	char	**new_stack;
	char	*arr;

	new_stack = malloc(sizeof(char *) * (s->size_a + 1));
	if (!new_stack)
		return (NULL);
	i = 0;
	while (i < s->size_a)
	{
		arr = malloc(sizeof(char) * (quaternary_len(s->size_a - 1) + 1));
		if (!arr)
		{
			while (i--)
				free(new_stack[i - 1]);
			return (free(new_stack), NULL);
		}
		fill_b_arr(s, &arr);
		new_stack[i] = arr;
		i++;
	}
	new_stack[i] = NULL;
	return (new_stack);
}

void	fill_b_arr(t_list *s, char **arr)
{
	int	j;

	j = 0;
	while (j < quaternary_len(s->size_a - 1))
	{
		(*arr)[j] = ' ';
		j++;
	}
	(*arr)[j] = '\0';
}
