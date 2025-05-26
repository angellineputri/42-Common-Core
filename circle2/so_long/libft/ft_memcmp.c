/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:52:44 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 21:00:01 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;
	size_t				i;
	int					diff;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	n--;
	while (n--)
	{
		if (str1[i] == str2[i])
			i++;
	}
	diff = str1[i] - str2[i];
	return (diff);
}

/*
int	main()
{
	char	str1[15] = "abcdefghij";
	char	str2[15] = "abcdefgxyz";
	size_t	n = 7;

	printf("str 1: %s\n", str1);
	printf("str 2: %s\n", str2);
	printf("n    : %zu\n", n);
	printf("original memcmp: %d\n", memcmp(str1, str2, n));
	printf("ft_memcmp      : %d\n", ft_memcmp(str1, str2, n));
	
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	printf("lalalal\n%d\n:", ft_memcmp(s2, s3, 4));
	printf("lilili\n%d\n:", memcmp(s2, s3, 4));
}
*/
