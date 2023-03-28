/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:37:00 by aandom            #+#    #+#             */
/*   Updated: 2023/03/22 16:28:13 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **st_a)
{
	if (((*st_a)->value > (*st_a)->next->value) && \
	((*st_a)->value < (*st_a)->next->next->value))
		swap(st_a, 1);
	else if (((*st_a)->value > (*st_a)->next->next->value) && \
	((*st_a)->next->value < (*st_a)->next->next->value))
		*st_a = rotate(st_a, 1);
	else if (((*st_a)->value < (*st_a)->next->value) && \
	((*st_a)->value > (*st_a)->next->next->value))
		*st_a = rev_rotate(st_a, 1);
	else if ((*st_a)->value > (*st_a)->next->value && \
	(*st_a)->next->value > (*st_a)->next->next->value)
	{
		swap(st_a, 1);
		*st_a = rev_rotate(st_a, 1);
	}
	else if ((*st_a)->next->value == findmax(st_a) && \
	(*st_a)->value < (*st_a)->next->next->value)
	{
		*st_a = rev_rotate(st_a, 1);
		swap(st_a, 1);
	}
}

void	sort_four(t_list **st_a, t_list **st_b, int max)
{
	t_list	*tmp;
	int		i;

	tmp = *st_a;
	i = 0;
	while (tmp->value != max)
	{
		tmp = tmp->next;
		i++;
	}
	if (i >= 2)
	{
		while ((*st_a)->value != max)
			rev_rotate(st_a, 1);
	}
	else
	{
		while ((*st_a)->value != max)
			rotate(st_a, 1);
	}
	push(st_a, st_b, 1);
	sort_three(st_a);
	push(st_b, st_a, 2);
	rotate(st_a, 1);
}

void	sort_five(t_list **st_a, t_list **st_b, t_array array)
{
	int		i;
	t_list	*tmp;

	tmp = *st_a;
	i = 0;
	while (tmp->value != array.arr_max)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > 2)
	{
		while ((*st_a)->value != array.arr_max)
			rev_rotate(st_a, 1);
	}
	else
	{
		i = 0;
		while ((*st_a)->value != array.arr_max && i++ < 5)
			rotate(st_a, 1);
	}
	push(st_a, st_b, 1);
	sort_four(st_a, st_b, findmax(st_a));
	push(st_b, st_a, 2);
	rotate(st_a, 1);
}

void	quik_sort(t_list **st_a, t_list **st_b, t_array *array)
{
	if (array->len == 2)
		swap(st_a, 1);
	else if (array->len == 3)
		sort_three(st_a);
	else if (array->len == 4)
		sort_four(st_a, st_b, array->arr_max);
	else
		sort_five(st_a, st_b, *array);
}
