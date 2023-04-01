/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:31:10 by aandom            #+#    #+#             */
/*   Updated: 2022/12/22 09:31:10 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_sign(const char *str, int *sign, int i)
{
	int	c;

	c = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = *sign * -1;
		c++;
	}
	return (c);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	num;
	int		sign;
	int		c;

	i = 0;
	num = 0;
	sign = 1;
	c = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	i = i + set_sign(nptr, &sign, i);
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - '0');
		c++;
		i++;
	}
	if (num * sign > INT_MAX || num * sign < INT_MIN || c > 10)
		return (0);
	return ((int)num * sign);
}
