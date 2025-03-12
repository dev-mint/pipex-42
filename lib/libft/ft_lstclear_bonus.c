/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:31:18 by anachat           #+#    #+#             */
/*   Updated: 2024/11/09 14:21:10 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = tmp;
	}
	*lst = NULL;
}
