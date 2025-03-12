/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:07:33 by anachat           #+#    #+#             */
/*   Updated: 2024/11/09 14:21:41 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;
	size_t			i;

	ch = (unsigned char) c;
	p = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (p[i] == ch)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
