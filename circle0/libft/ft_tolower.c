/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:20:16 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/15 13:30:10 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
int	main()
{
	char	c = 'A';
	char	ori_c = 'A';
	printf("char to convert : %c\n", c);
	printf("original tolower: %c\n", tolower(ori_c));
	printf("ft_tolower      : %c\n", ft_tolower(c));
}
*/
