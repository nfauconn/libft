/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:01:03 by nfauconn          #+#    #+#             */
/*   Updated: 2019/12/02 21:34:25 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*nombre;
	int		i;
	long	nb;

	nb = (long)n;
	i = len(nb);
	if (!(nombre = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nombre[i--] = '\0';
	if (nb == 0)
	{
		nombre[i] = '0';
	}
	else if (nb < 0)
	{
		nombre[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		nombre[i--] = (nb % 10 + '0');
		nb = nb / 10;
	}
	return (nombre);
}
