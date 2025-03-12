/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:27:19 by anachat           #+#    #+#             */
/*   Updated: 2025/03/09 14:05:33 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fix_val(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	nb;

	s = 1;
	i = 0;
	nb = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || str[i] == '	'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		if (nb > 922337203685477580
			|| ((nb == 922337203685477580) && str[i] > '7'))
			return (fix_val(s));
		nb = nb * 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb * s);
}
