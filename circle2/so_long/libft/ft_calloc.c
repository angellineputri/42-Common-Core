/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:53:03 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 20:43:27 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*memory;
	unsigned char		*ptr;
	size_t				i;

	memory = (void *)malloc(nmemb * size);
	i = 0;
	if (!memory)
		return (NULL);
	ptr = (unsigned char *)memory;
	while (i < size * nmemb)
	{
		ptr[i] = 0;
		i++;
	}
	return (memory);
}

/*
int	main() 
{
	size_t nmemb = 8539;
    	size_t size = sizeof(int);

	char *array = (char *)ft_calloc(nmemb, size);
	char *ori = (char *)calloc(nmemb, size);
	if (array == NULL)
		printf("ft_calloc: memory allocation failed\n");
	if (ori == NULL)
		printf("ori: memory allocation failed\n");
	if (ori != NULL)
		printf("ori: memory allocation success\n");
	if (array != NULL)
		printf("ft_calloc: memory allocation success\n");
}
*/