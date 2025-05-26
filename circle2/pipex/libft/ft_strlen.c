/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:37:01 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/14 13:37:06 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/*
int	main(int argc, char **argv)
{
	char	*h;
	h = argv[1];
	
	if (argc == 2)
	{
		printf("original: %lu\n", strlen(h));
		printf("ft_strlen: %lu\n", ft_strlen(h));
	}
}
*/
