/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:18:10 by anachat           #+#    #+#             */
/*   Updated: 2025/01/24 09:44:07 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	ch = (unsigned char) c;
	str = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		str[i] = ch;
		i++;
	}
	return (b);
}
