/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:03:57 by anachat           #+#    #+#             */
/*   Updated: 2025/03/09 14:06:48 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_concat(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		return (free(s1), s1 = NULL, str_clone(s2));
	str = malloc((str_len(s1) + str_len(s2) + 1) * sizeof(char));
	if (!str)
		return (free(s1), s1 = NULL, NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

char	*str_clone(char *s1)
{
	char		*str;

	str = str_cut(s1, 0, str_len(s1));
	if (str == NULL)
		return (NULL);
	return (str);
}

size_t	str_len(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*str_cut(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	if (start > str_len(s))
		return (str_clone(""));
	if (len > str_len(s + start))
		len = str_len(s + start);
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*find_char(char *s, int c)
{
	unsigned int	i;
	char			ch;

	if (!s)
		return (NULL);
	ch = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ch)
		return ((char *) &s[i]);
	return (NULL);
}
