/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:20:16 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/15 13:28:01 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
int	main()
{
	char	c = 'a';
	char	ori_c = 'a';
	printf("char to convert : %c\n", c);
	printf("original toupper: %c\n", toupper(ori_c));
	printf("ft_toupper      : %c\n", ft_toupper(c));
}
*/
