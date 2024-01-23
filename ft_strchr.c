/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:06:43 by nfauconn          #+#    #+#             */
/*   Updated: 2022/08/07 00:41:46 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	to_find;
	char	*s1;

	to_find = (char)c;
	if (!s)
		return (NULL);
	s1 = (char *)s;
	if (to_find == '\0')
		return (&s1[ft_strlen(s1)]);
	while (s1 && *s1)
	{
		if (*s1 == to_find)
			return (s1);
		s1++;
	}
	return (NULL);
}
