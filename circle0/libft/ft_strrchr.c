/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:30:29 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 17:39:07 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	save;

	c %= 256;
	i = 0;
	save = -1;
	while (s[i])
	{
		if (s[i] == c)
			save = i;
		i++;
	}
	if (save != -1)
		return ((char *)s + save);
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

/*
int	main()
{
	int	c = 'c';
	char	*str = "abcdefghabcdefgh";
	
	printf("string: %s\n", str);
	printf("c     : %c\n", c);
	printf("original return value : %s\n", strrchr(str, c));
	printf("ft_strchr return value: %s\n", ft_strrchr(str, c));
}
*/
