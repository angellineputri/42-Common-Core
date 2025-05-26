/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:25:13 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 20:43:01 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	back(char const *s1, char const *set, int end)
{
	int	temp;
	int	len;
	int	i;

	len = 0;
	while (s1[end])
	{
		temp = len;
		i = 0;
		while (set[i])
		{
			if (s1[end] == set[i])
			{
				len++;
				break ;
			}
			i++;
		}
		if (temp == len)
			break ;
		end--;
	}
	return (len);
}

int	front(char const *s1, char const *set)
{
	int	len;
	int	temp;
	int	i;
	int	k;

	len = 0;
	k = 0;
	while (s1[k])
	{
		temp = len;
		i = 0;
		while (set[i])
		{
			if (s1[k] == set[i])
			{
				len++;
				break ;
			}
			i++;
		}
		if (temp == len)
			break ;
		k++;
	}
	return (len);
}

int	length(char const *s1)
{
	int		len;

	len = 0;
	while (s1[len])
		len++;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	char	*trimmed_ptr;
	int		trimmed_len;
	int		front_len;
	int		back_len;

	if (set == NULL)
		return ((char *)s1);
	trimmed_len = length(s1);
	front_len = front(s1, set);
	back_len = back(s1, set, trimmed_len - 1);
	trimmed_len = trimmed_len - front_len;
	if (trimmed_len != 0)
		trimmed_len -= back_len;
	trimmed = (char *)malloc((trimmed_len + 1) * sizeof(char));
	trimmed_ptr = trimmed;
	if (trimmed == NULL)
		return (NULL);
	while (front_len--)
		s1++;
	while (trimmed_len--)
		*trimmed_ptr++ = *s1++;
	*trimmed_ptr = '\0';
	return (trimmed);
}

/*
int	main()
{
	const char	s1[50] = "rqbcd  emfgn hiojklmnopqr";
	const char	set[5] = "aqr";
	char			*trimmed = ft_strtrim(s1, set);

	printf("s1, string to be trimmed    : %s\n", s1);
	printf("set, ref set of char to trim: %s\n", set);
	printf("the trimmed string          : %s\n", trimmed);
}
*/
