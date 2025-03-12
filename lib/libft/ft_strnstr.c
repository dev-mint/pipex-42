/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:19:49 by anachat           #+#    #+#             */
/*   Updated: 2024/11/15 11:52:32 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	char	*str;

	str = (char *)haystack;
	if (needle[0] == '\0')
		return (str);
	i = 0;
	while (i < len && str[i])
	{
		j = 0;
		while (needle[j] && (i + j) < len && needle[j] == str[i + j])
			j++;
		if (needle[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}
