/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:12:15 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 15:47:33 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		strlen;
	char	*dup;

	strlen = 0;
	while (s[strlen])
		strlen++;
	dup = (char *)malloc((strlen + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	strlen = 0;
	while (s[strlen])
	{
		dup[strlen] = s[strlen];
		strlen++;
	}
	dup[strlen] = '\0';
	return (dup);
}

/*
int	main()
{
	char	s[9] = "abcdefgh";
	char	*original = strdup(s);
	char	*dup = ft_strdup(s);
	printf("original strdup: %s\n", original);
	printf("ft_strdup      : %s\n", dup);
}
*/
