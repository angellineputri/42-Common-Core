/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:02:25 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/21 15:57:49 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_len(char const *s, char c)
{
	int	len;

	len = 0;
	if (*s != c && *s != '\0')
		len++;
	while (*s)
	{
		if (*s == c && *(s + 1) != '\0' && *(s + 1) != c)
			len++;
		s++;
	}
	return (len);
}

static char	*arr_block(char const *s, char c)
{
	char	*block;
	char	*block_ptr;
	int		len;

	len = 0;
	while (s[len] && s[len] != c && s[len] != '\0')
		len++;
	block = (char *)malloc((len + 1) * sizeof(char));
	block_ptr = block;
	if (block == NULL)
		return (NULL);
	while (len--)
		*block_ptr++ = *s++;
	*block_ptr = '\0';
	return (block);
}

static int	check_arr(char **arr, char *block, int size)
{
	int	i;

	if (!block)
	{
		i = 0;
		while (i < size)
			free(arr[i++]);
		free(arr);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arrlen;
	int		i;

	arrlen = arr_len(s, c);
	arr = (char **)malloc((arrlen + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			arr[i] = arr_block(s, c);
			if (check_arr(arr, arr[i], i) == 0)
				return (NULL);
			i++;
		}
		while (*s && *s != c)
			s++;
		if (*s != '\0')
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

/*
int	main()
{
	char	s[100] = "a,b,c,d,e,f,g,h,i";
	char	c = ',';
	char	**arr = ft_split(s, c);
	int		i;

	i = 0;
	while (arr[i])
	{
		printf("array[%d]: %s\n", i, arr[i]);
		i++;
	}
}
*/
