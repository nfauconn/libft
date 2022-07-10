/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:13:46 by nfauconn          #+#    #+#             */
/*   Updated: 2022/07/10 13:19:13 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	find;
	unsigned char	*tab;

	find = (unsigned char)c;
	tab = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tab[i] == find)
			return (&tab[i]);
		i++;
	}
	return (NULL);
}
