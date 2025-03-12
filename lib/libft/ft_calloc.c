/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:16:56 by anachat           #+#    #+#             */
/*   Updated: 2024/11/11 18:26:24 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			n;

	p = NULL;
	n = count * size;
	if (count != 0 && n / count != size)
		return (NULL);
	p = malloc(n);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, n);
	return ((void *)p);
}
