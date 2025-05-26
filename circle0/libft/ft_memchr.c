/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:09:02 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 20:12:01 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	c %= 256;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	if (i < n && str[i] == (unsigned char)c)
		return (str + i);
	return (NULL);
}

/*
int	main()
{
	int		c = 'b';
	const void	*str = "abcdefghabcdefgh";
	size_t		n = 3;

	printf("string: %p\n", str);
	printf("c     : %c\n", c);
	printf("original return value : %s\n", (char *)memchr(str, c, n));
	printf("ft_strchr return value: %s\n", (char *)ft_memchr(str, c, n));
}
*/
