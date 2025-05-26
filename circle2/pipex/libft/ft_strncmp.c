/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:52:44 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 20:22:28 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (diff < -127)
		return (-1);
	if (diff > 127)
		return (1);
	return (diff);
}

/*
int	main()
{
	char	str1[9] = "abcdefgh";
	char	str2[9] = "abcdffgh";
	size_t	n = 0;

	printf("str 1: %s\n", str1);
	printf("str 2: %s\n", str2);
	printf("n    : %zu\n", n);
	printf("original strncmp: %d\n", strncmp(str1, str2, n));
	printf("ft_strncmp      : %d\n", ft_strncmp(str1, str2, n));
}
*/
