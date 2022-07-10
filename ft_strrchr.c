/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:23:13 by nfauconn          #+#    #+#             */
/*   Updated: 2022/07/10 11:50:59 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*s1;

	s1 = (char *)s;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (len >= 0)
	{
		if (s1[len] == c)
			return (&s1[len]);
		len--;
	}
	return (NULL);
}
