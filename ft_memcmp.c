/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:09:36 by nfauconn          #+#    #+#             */
/*   Updated: 2019/11/21 17:14:54 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*chaine1;
	const unsigned char	*chaine2;
	size_t				i;

	chaine1 = (const unsigned char *)s1;
	chaine2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (chaine1[i] == chaine2[i])
			i++;
		else
			return (chaine1[i] - chaine2[i]);
	}
	return (0);
}
