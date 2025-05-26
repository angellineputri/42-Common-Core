/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:03:32 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/14 14:13:56 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	index;

	str = s;
	index = 0;
	while (n--)
	{
		str[index] = '\0';
		index++;
	}
}

/*
int	main()
{
	char	str[21];
	char	sec_str[21];

	strcpy(str, "12345678901234567890");
	strcpy(sec_str, "12345678901234567890");

	printf("before original bzero: %s\n", str);
	printf("before ft_bzero: %s\n\n", sec_str);

	bzero(str + 7, 4*sizeof(char));
        printf("after original bzero: %s\n", str);
	ft_bzero(sec_str + 7, 4*sizeof(char));
	printf("after ft_bzero: %s\n", sec_str);
}
*/
