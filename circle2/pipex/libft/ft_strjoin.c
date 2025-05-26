/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:48:55 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/17 15:32:14 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	char	*joined_ptr;
	int		strlen_s1;
	int		strlen_s2;

	strlen_s1 = 0;
	strlen_s2 = 0;
	while (s1[strlen_s1])
		strlen_s1++;
	while (s2[strlen_s2])
		strlen_s2++;
	joined = (char *)malloc((strlen_s1 + strlen_s2 + 1) * sizeof(char));
	joined_ptr = joined;
	if (joined == NULL)
		return (NULL);
	while (*s1)
		*joined_ptr++ = *s1++;
	while (*s2)
		*joined_ptr++ = *s2++;
	*joined_ptr = '\0';
	return (joined);
}

/*
int	main()
{
	const char	s1[9] = "abcdefgh";
	const char	s2[11] = "1234567890";
	char			*joined = ft_strjoin(s1, s2);
	printf("s1 prefix : %s\n", s1);
	printf("s2 suffix : %s\n", s2);
	printf("joined str: %s\n", joined);
}
*/
