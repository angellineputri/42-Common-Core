/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:03:32 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 19:19:19 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*source;

	if (dest == NULL && src == NULL)
		return (NULL);
	str = (char *)dest;
	source = (char *)src;
	while (n--)
		*str++ = *source++;
	return (dest);
}

/*
int	main()
{
	char	src[9] = "12345678";
	char	str[9] = "12345678";
	char	original_dest[15] = "abcd";
	char	ft_memcpy_dest[15] = "abcd";
	
	printf("source: %s\n", src);
	
	memcpy(original_dest, src, 3);
	ft_memcpy(ft_memcpy_dest, str, 3);
	printf("memcpy: %s\n", original_dest);
	printf("ft_memcpy: %s\n", ft_memcpy_dest);
	
	printf("\nsource           : %s\n", src);
	memcpy(src + 3, src, 4*sizeof(char));
	ft_memcpy(str + 3, str, 4*sizeof(char));
	printf("memcpy overlap   : %s\n", src);
	printf("ft_memcpy overlap: %s\n", str);

	ft_memcpy(((void *)0), ((void *)0), 3);
}
*/
