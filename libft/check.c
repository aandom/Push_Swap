/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:07:42 by aandom            #+#    #+#             */
/*   Updated: 2023/03/07 02:07:42 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_zero(char *str, char *s2)
{
	if (ft_strlen(str) != ft_strlen(s2))
		return (0);
	while (*str && *s2)
	{
		if (*str != *s2)
			return (0);
		str++;
		s2++;
	}
	if ((!*str && !*s2))
		return (1);
	return (0);
}

int	all_digit(char *s)
{
	int	c;

	c = 0;
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
		c++;
	}
	if (c == 0)
		return (0);
	return (1);
}

char	**call_split(int ac, char **av, int *i, int *code)
{
	char	**ar;

	*i = 1;
	*code = 0;
	if (ac == 2)
	{
		ar = ft_split(av[1], ' ');
		if (ar == 0)
			return (0);
		*code = 1;
		*i = 0;
	}
	else
		ar = av;
	return (ar);
}

int	ft_check_args(int ac, char **av)
{
	char	**ar;
	int		i;
	int		code;

	ar = call_split(ac, av, &i, &code);
	if (ar == 0)
		return (0);
	while (ar[i])
	{
		if ((!ft_atoi(ar[i]) && !is_zero(ar[i], "0")) || !all_digit(ar[i]))
		{
			if (code == 1)
				clean(ar);
			return (0);
		}
		i++;
	}
	if (code == 1)
		clean(ar);
	return (1);
}
