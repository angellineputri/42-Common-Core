/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:30:29 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 17:44:23 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	c %= 256;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

/*
int	main()
{
	int	c = 'b' + 256;
	char	*str = "abcdefghabcdefgh";
	
	printf("string: %s\n", str);
	printf("c     : %c\n", c);
	printf("original return value : %s\n", strchr(str, c));
	printf("ft_strchr return value: %s\n", ft_strchr(str, c));
}
*/
