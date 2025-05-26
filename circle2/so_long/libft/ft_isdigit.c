/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:11:03 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 14:52:48 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	char	h;
	h = argv[1][0];
	if (argc == 2)
	{
		printf("original: %d\n", isdigit(h));
		printf("ft_isdigit: %d", ft_isdigit(h));
		if (isdigit(h))
			printf("\nits a digit1");
		if (ft_isdigit(h))
			printf("\nits a digit2");
	}
}
*/
