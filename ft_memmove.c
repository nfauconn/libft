/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:53:30 by nfauconn          #+#    #+#             */
/*   Updated: 2022/07/08 18:38:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest_addr;
	unsigned char	*source_addr;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst == src || !len)
		return (dst);
	dest_addr = dst;
	source_addr = (void *)src;
	if (source_addr > dest_addr && source_addr - dest_addr < (int)len)
		while (len--)
			*dest_addr++ = *source_addr++;
	else if (dest_addr < source_addr && dest_addr - source_addr < (int)len)
		while (len--)
			dest_addr[len] = source_addr[len];
	else
		memcpy(dst, src, len);
	return (dst);
}
