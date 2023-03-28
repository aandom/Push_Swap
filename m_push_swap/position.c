/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:33:38 by aandom            #+#    #+#             */
/*   Updated: 2023/03/24 16:43:34 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cur_position(t_list **lst)
{
	t_list	*tmp;
	int		pos;

	pos = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp->pos = pos;
		tmp = tmp->next;
		pos++;
	}
	return ;
}

int	set_pos(t_list **lst, int tar_index, int tar_pos)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->index < tar_index)
		{
			tar_pos = tmp->pos;
			tar_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (tar_pos);
}

int	get_tar_pos(t_list **lst, int n_index, int tar_index, int tar_pos)
{
	t_list	*tmp;
	int		tartmp;

	tartmp = tar_index;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->index > n_index && tmp->index < tar_index)
		{
			tar_pos = tmp->pos;
			tar_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (tar_index != tartmp)
		return (tar_pos);
	return (set_pos(lst, tar_index, tar_pos));
}

void	target_pos(t_list **st_a, t_list **st_b)
{
	int		t_pos;
	t_list	*tmp;
	int		maxpos;

	cur_position(st_a);
	cur_position(st_b);
	tmp = *st_b;
	t_pos = 0;
	maxpos = ft_lstsize(*st_a) + ft_lstsize(*st_b);
	while (tmp)
	{
		t_pos = get_tar_pos(st_a, tmp->index, maxpos, t_pos);
		tmp->t_pos = t_pos;
		tmp = tmp->next;
	}
	return ;
}
