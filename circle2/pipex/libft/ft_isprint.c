/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:11:03 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/13 17:57:28 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	char	h;
	h = argv[1][0];

	if (argc == 2)
	{
		printf("original: %d\n", isprint(h));
		printf("ft_isalnum: %d", ft_isprint(h));
		if (isprint(h))
			printf("\nits a printable char1");
		if (ft_isprint(h))
			printf("\nits a printable char2");
	}
}
*/
