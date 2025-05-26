/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:27:03 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/17 15:19:09 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sub;
	unsigned int		i;
	unsigned int		s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (len > s_len - start)
		len = s_len - start;
	if (start > s_len)
		len = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (len-- && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	if (start > s_len)
		i = 0;
	sub[i] = '\0';
	return (sub);
}

/*
int	main()
{
	char	src[9] = "abcdefgh";
	int		start = 3;
	size_t	len = 4;
	char	*sub = ft_substr(src, start, len);
	printf("sub: %s\n", sub);
	printf("2: %s\n", ft_substr("tripouille", 100, 1));
}
*/