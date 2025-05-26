/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:22:01 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/18 14:59:56 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	change(unsigned int i, char c)
{
	if (i % 5 == 0)
		return ('.');
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return ('a');
	else if (c >= '0' && c <= '9')
		return ('n');
	else
		return ('x');
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
int	main()
{
	char const	s[11] = "12y4567U90";
	char			*result = ft_strmapi(s, &change);
	int				i;
	
	i = 0;
	while (result[i])
	{
		printf("result[%d]: %c\n", i, result[i]);
		i++;
	}
}
*/
