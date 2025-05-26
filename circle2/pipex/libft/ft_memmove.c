/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:03:32 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 19:21:43 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*str;
	const unsigned char	*source;

	str = dest;
	source = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		while (n--)
			str[n] = source[n];
	}
	else
	{
		while (n--)
			*str++ = *source++;
	}
	return (dest);
}

/*
void	compare(void *dest, const void *src)
{
	if (dest > src)
		printf("dest > src\n");
	if (dest == src)
		printf("dest == src\n");
	if (dest < src)
		printf("dest < src\n");
	printf("dest mem address : %p\n", dest);
	printf("src mem address  : %p\n", src);
}

int	main()
{
	char	tes[10] = "123456789";
	char    src[23] = "12345678901234567890";
	char	original_src[23] = "12345678901234567890";
	char    original_dest[15] = "abcdefgh";
        char    ft_memmove_dest[15] = "abcdefgh";

	printf("\n-----no overlapping-----\n");	
	printf("source  : %s\n", src);
	memmove(original_dest, original_src, 3);
	ft_memmove(ft_memmove_dest, src, 3);
	printf("compare dest and source: ");
	compare(ft_memmove_dest, src);
	printf("memmove   : %s\n", original_dest);
	printf("ft_memmove: %s\n", ft_memmove_dest);
	
	printf("\n-----overlapping-----\n");
	printf("source            : %s\n", src);
	memmove(original_src + 4, original_src + 9, 5*sizeof(char));
	ft_memmove(src + 4, src + 9, 5*sizeof(char));
	printf("compare dest and source: ");
	compare(src + 4, src + 9);
	printf("memmove overlap   : %s\n", original_src);
	printf("ft_memmove overlap: %s\n", src);

	printf("\n-----memory blocks are allocated from 
	higher memory address to lower\n");

	printf("-----so the address of the earlier declared 
	variable is 'bigger'\n");
	printf("memory address of the earlier 
	declared var, src: %p\n", src);
	printf("memory address of the newer 
	declared var, dest: %p\n", ft_memmove_dest);

	printf("\n-----in a string, the char is 
	assigned to its memory from the end'\n");
	printf("memory address of tes index 0: %p\n", &tes[0]);
        printf("memory address of tes index 1: %p\n", &tes[1]);
}
*/
