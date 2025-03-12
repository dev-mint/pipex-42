/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:06:28 by anachat           #+#    #+#             */
/*   Updated: 2024/11/07 22:37:22 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elm;

	if (!lst || !new)
		return ;
	last_elm = ft_lstlast((*lst));
	if (!last_elm)
		(*lst) = new;
	else
		(*last_elm).next = new;
}
