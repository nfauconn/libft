/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:01:03 by nfauconn          #+#    #+#             */
/*   Updated: 2022/07/08 17:39:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*nombre;
	int		i;
	long	nb;

	nb = (long)n;
	i = len(nb);
	printf("len = %d\n", i);
	nombre = (char *)malloc(sizeof(char) * (i + 1));
	if (!nombre)
		return (NULL);
	nombre[i--] = '\0';
	if (nb == 0)
		nombre[i] = '0';
	if (nb < 0)
	{
		nombre[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		nombre[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (nombre);
}
