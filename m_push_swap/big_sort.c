/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:15:53 by aandom            #+#    #+#             */
/*   Updated: 2023/03/23 23:27:18 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cost(t_list **lst1, t_list **lst2)
{
	t_list	*st_a;
	t_list	*st_b;
	int		len_a;
	int		len_b;

	st_a = *lst1;
	st_b = *lst2;
	len_a = ft_lstsize(st_a);
	len_b = ft_lstsize(st_b);
	while (st_b)
	{
		st_b->c_b = st_b->pos;
		if (st_b->pos > len_b / 2)
			st_b->c_b = (len_b - st_b->pos) * -1;
		st_b->c_a = st_b->t_pos;
		if (st_b->t_pos > len_a / 2)
			st_b->c_a = (len_a - st_b->t_pos) * -1;
		st_b = st_b->next;
	}
	return ;
}

void	big_sort(t_list **st_a, t_list **st_b, t_array *tmp)
{
	int	len;

	while (ft_lstsize(*st_a) > 3)
	{
		len = 0;
		while (len++ < tmp->len / 2 && ft_lstsize(*st_a) > 3)
		{
			if ((*st_a)->value < tmp->med)
				push(st_a, st_b, 1);
			else
				*st_a = rotate(st_a, 1);
		}
		free(tmp->arr);
		med_array(st_a, tmp);
	}
	sort_three(st_a);
	while (*st_b)
	{
		target_pos(st_a, st_b);
		find_cost(st_a, st_b);
		shortest_move(st_a, st_b);
	}
}
