/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:39:43 by anachat           #+#    #+#             */
/*   Updated: 2025/02/06 14:32:42 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char sep)
{
	size_t	i;
	int		wc;
	int		check;

	i = 0;
	wc = 0;
	check = 1;
	while (str[i])
	{
		if (check && str[i] != sep)
		{
			check = 0;
			wc++;
		}
		if (str[i] == sep)
			check = 1;
		i++;
	}
	return (wc);
}

static void	*free_mem(char **words, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

static char	*fill_mem(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = ft_calloc((end - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**fill_array(char **arr, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (start < 0 && s[i] != c)
			start = i;
		else if (start >= 0 && (i == ft_strlen(s) || s[i] == c))
		{
			arr[j] = fill_mem((char *)s, start, i);
			if (!arr[j])
				return (free_mem(arr, j));
			start = -1;
			j++;
		}
		i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	if (!count)
		return (NULL);
	arr = ft_calloc((count + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill_array(arr, s, c));
}
