/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:34:30 by anachat           #+#    #+#             */
/*   Updated: 2024/11/07 15:45:31 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(src);
	if (dstsize == 0 && !dest && src)
		return (s_len);
	d_len = ft_strlen(dest);
	if (dstsize <= d_len)
		return (dstsize + s_len);
	i = 0;
	while (src[i] && (d_len + i) < (dstsize - 1))
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}
