/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:44:57 by aandom            #+#    #+#             */
/*   Updated: 2023/03/23 16:04:18 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findmax(t_list **lst)
{
	int		m;
	t_list	*tmp;

	if (!*lst)
		return (0);
	tmp = *lst;
	m = tmp->value;
	while (tmp)
	{
		if (m < tmp->value)
			m = tmp->value;
		tmp = tmp->next;
	}
	return (m);
}

void	med_array(t_list **lst, t_array *array)
{
	t_list	*stack;
	int		i;

	stack = *lst;
	i = 0;
	array->len = ft_lstsize(stack);
	array->arr = (int *) malloc(sizeof(int) * (array->len + 1));
	if (!array->arr)
		return ;
	while (stack)
	{
		array->arr[i] = stack->value;
		i++;
		stack = stack->next;
	}
	array->arr[i] = '\0';
	sort_arr(array);
	array->arr_max = array->arr[i - 1];
	array->arr_min = array->arr[0];
	return ;
}

void	index_stack(t_list **lst, t_array *array)
{
	int		i;
	t_list	*stack;

	stack = *lst;
	while (stack)
	{
		i = 0;
		while (i < array->len)
		{
			if (array->arr[i] == stack->value)
			{
				stack->index = i + 1;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
	return ;
}

void	sort_arr(t_array *array)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < array->len - 1)
	{
		if (array->arr[i] > array->arr[i + 1])
		{
			tmp = array->arr[i];
			array->arr[i] = array->arr[i + 1];
			array->arr[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	array->med = array->arr[array->len / 2];
}
