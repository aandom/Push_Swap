/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:14:53 by aandom            #+#    #+#             */
/*   Updated: 2023/03/24 17:47:21 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_and_rrb(t_list **st_a, t_list **st_b, int *c_a, int *c_b)
{
	while (*c_a < 0 && *c_b < 0)
	{
		*st_a = rev_rotate(st_a, 3);
		*st_b = rev_rotate(st_b, 3);
		ft_printf("rrr\n");
		(*c_a)++;
		(*c_b)++;
	}
}

void	ra_and_rb(t_list **st_a, t_list **st_b, int *c_a, int *c_b)
{
	while (*c_a > 0 && *c_b > 0)
	{
		*st_a = rotate(st_a, 3);
		*st_b = rotate(st_b, 3);
		ft_printf("rr\n");
		(*c_a)--;
		(*c_b)--;
	}
}

void	multi_rotate(t_list **lst, int *cost, int code)
{
	if (*cost > 0)
	{
		while (*cost > 0)
		{
			*lst = rotate(lst, code);
			(*cost)--;
		}
	}
	else
	{
		while (*cost < 0)
		{
			*lst = rev_rotate(lst, code);
			(*cost)++;
		}
	}
}
