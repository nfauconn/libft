/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:06:43 by nfauconn          #+#    #+#             */
/*   Updated: 2022/07/10 11:47:10 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;

	if (!s)
		return (NULL);
	s1 = (char *)s;
	if (c == '\0')
		return (&s1[ft_strlen(s1)]);
	while (s1 && *s1)
	{
		if (*s1 == c)
			return (s1);
		s1++;
	}
	return (NULL);
}
