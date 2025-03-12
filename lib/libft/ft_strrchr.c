/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:11:21 by anachat           #+#    #+#             */
/*   Updated: 2024/11/16 12:02:02 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	size_t	n;
	char	ch;

	ch = (char) c;
	i = ft_strlen((char *)str);
	n = i;
	while (i <= n)
	{
		if (str[i] == ch)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
