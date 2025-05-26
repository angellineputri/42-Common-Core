/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:53:48 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/18 15:04:58 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	change(unsigned int i, char *s)
{
	if (i % 2 == 0)
		*s = '.';
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
int	main()
{
	char	s[11] = "1234567890";
	printf("before: %s\n", s);
	ft_striteri(s, &change);
	printf("after : %s\n", s);
}
*/
