/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:07:02 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/23 14:24:49 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int					sign;
	unsigned long long	nbr;

	nbr = 0;
	sign = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		nbr = (nbr * 10) + (*s - '0');
		s++;
	}
	if (nbr > LLONG_MAX)
		return ((-1) * sign);
	return ((int)(nbr * sign));
}
