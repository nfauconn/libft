/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:20:44 by nfauconn          #+#    #+#             */
/*   Updated: 2024/02/06 11:26:24 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	curr = *lst;
	if (curr)
		next = curr->next;
	while (curr)
	{
		if (curr->content)
			del(curr->content);
		free(curr);
		curr = next;
		if (curr)
			next = curr->next;
	}
	*lst = NULL;
}
