/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:08:58 by aandom            #+#    #+#             */
/*   Updated: 2023/03/23 13:36:42 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_of_n(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	do_shortest_move(t_list **st_a, t_list **st_b, int c_a, int c_b)
{
	if (c_a < 0 && c_b < 0)
		rra_and_rrb(st_a, st_b, &c_a, &c_b);
	else if (c_a > 0 && c_b > 0)
		ra_and_rb(st_a, st_b, &c_a, &c_b);
	multi_rotate(st_a, &c_a, 1);
	multi_rotate(st_b, &c_b, 2);
	push(st_b, st_a, 2);
	return ;
}

void	shortest_move(t_list **lst1, t_list **lst2)
{
	int		shortest;
	int		c_a;
	int		c_b;
	t_list	*st_b;

	st_b = *lst2;
	c_a = st_b->c_a;
	c_b = st_b->c_b;
	shortest = ft_lstsize(*lst1) + ft_lstsize(*lst2);
	while (st_b)
	{
		if (abs_of_n(st_b->c_a) + abs_of_n(st_b->c_b) < abs_of_n(shortest))
		{
			shortest = abs_of_n(st_b->c_b) + abs_of_n (st_b->c_a);
			c_a = st_b->c_a;
			c_b = st_b->c_b;
		}
		st_b = st_b->next;
	}
	do_shortest_move(lst1, lst2, c_a, c_b);
	return ;
}
