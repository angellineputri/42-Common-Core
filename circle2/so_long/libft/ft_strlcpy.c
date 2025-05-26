/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:43:49 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/15 13:06:07 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (size < 1)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
int	main()
{
	char	src[11] = "1234567890";
	char	dest[9] = "abcdefgh";

	printf("source: %s\n", src);
	printf("dest before: %s\n", dest);
	printf("return value: %zu\n", ft_strlcpy(dest + 3, src, 5));
	printf("dest after : %s\n", dest);
}
*/
