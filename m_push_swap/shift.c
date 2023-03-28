/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:41:08 by aandom            #+#    #+#             */
/*   Updated: 2023/03/23 13:39:04 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_list **st_a, int min)
{
	t_list	*tmp;
	int		min_pos;

	tmp = *st_a;
	cur_position(st_a);
	min_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->value == min)
			return (tmp->pos);
		tmp = tmp->next;
	}
	return (min_pos);
}

void	shift_st_a(t_list **st_a)
{
	int		min_pos;
	int		size;
	t_array	arr;

	size = ft_lstsize(*st_a);
	med_array(st_a, &arr);
	min_pos = get_min_pos(st_a, arr.arr_min);
	if (min_pos > size / 2)
	{
		while (min_pos < size)
		{
			*st_a = rev_rotate(st_a, 1);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			*st_a = rotate(st_a, 1);
			min_pos--;
		}
	}
	free(arr.arr);
}
