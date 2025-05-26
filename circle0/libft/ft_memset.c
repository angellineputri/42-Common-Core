/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:03:32 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 14:45:26 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n--)
		*str++ = c;
	return (s);
}

/*
int	main()
{
	char	str[11] = "1234567890";
	char	sec_str[11] = "1234567890";

	printf("before               : %s\n", sec_str);
	memset(str, '.', 5*sizeof(char));
        printf("after original memset: %s\n", str);
	ft_memset(sec_str, '.', 5*sizeof(char));
	printf("after ft_memset      : %s\n", sec_str);
}
*/
