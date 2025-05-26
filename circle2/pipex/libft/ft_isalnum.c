/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:11:03 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/13 17:57:38 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (8);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	char	h;
	h = argv[1][0];

	if (argc == 2)
	{
		printf("original: %d\n", isalnum(h));
		printf("ft_isalnum: %d", ft_isalnum(h));
		if (isalnum(h))
			printf("\nits an alnum1");
		if (ft_isalnum(h))
			printf("\nits an alnum2");
	}
}
*/
