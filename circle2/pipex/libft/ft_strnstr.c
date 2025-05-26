/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:30:16 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 21:12:39 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_little;
	size_t	little_len;

	i_big = 0;
	i_little = 0;
	little_len = 0;
	while (little[little_len])
		little_len++;
	while (big[i_big] && little[i_little] && i_big < len)
	{
		if (big[i_big] != little[i_little])
		{
			i_big -= i_little;
			i_little = 0;
		}
		else
			i_little++;
		i_big++;
	}
	if (i_little == little_len)
		return ((char *)big + i_big - i_little);
	return (NULL);
}
/*
int	main()
{
	char	big[32] = "aaabcabcd";
	char	little[6] = "abcd";
	size_t	len = 9;

	printf("big    : %s\n", big);
	printf("little : %s\n", little);
	printf("len    : %zu\n", len);
	printf("ft_strnstr: %s\n", ft_strnstr(big, little, len));
}
*/