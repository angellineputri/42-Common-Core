/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:11:03 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/13 17:41:40 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	char	h;
	h = argv[1][0];

	if (argc == 2)
	{
		printf("original: %d\n", isalpha(h));
		printf("ft_isalpha: %d", ft_isalpha(h));
		if (isalpha(h))
			printf("\nits an alphabet1");
		if (ft_isalpha(h))
			printf("\nits an alphabet2");
	}
}
*/
