/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:50:33 by aandom            #+#    #+#             */
/*   Updated: 2023/03/06 00:50:33 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(t_list **lst, int code)
{
	int		value;
	int		index;

	if (!*lst)
		return ;
	value = (*lst)->next->value;
	index = (*lst)->next->index;
	(*lst)->next->value = (*lst)->value;
	(*lst)->next->index = (*lst)->index;
	(*lst)->value = value;
	(*lst)->index = index;
	if (code == 1)
		ft_printf ("sa\n");
	else if (code == 2)
		ft_printf("sb\n");
	return ;
}

void	push(t_list **lst1, t_list **lst2, int code)
{
	t_list	*tmp;

	if (!*lst1)
		return ;
	tmp = *lst1;
	*lst1 = (*lst1)->next;
	tmp->next = NULL;
	ft_lstadd_front(lst2, tmp);
	if (code == 1)
		ft_printf ("pb\n");
	else if (code == 2)
		ft_printf("pa\n");
	return ;
}

t_list	*rotate(t_list **lst, int code)
{
	t_list	*tmp;
	t_list	*last;

	if (!*lst)
		return (NULL);
	tmp = *lst;
	*lst = (*lst)->next;
	last = ft_lstnew(tmp->value);
	last->index = tmp->index;
	free(tmp);
	ft_lstadd_back(lst, last);
	if (code == 1)
		ft_printf ("ra\n");
	else if (code == 2)
		ft_printf("rb\n");
	return (*lst);
}

t_list	*rev_rotate(t_list **lst, int code)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*tmp2;

	last = ft_lstlast(*lst);
	tmp2 = ft_lstnew(last->value);
	tmp2->index = last->index;
	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->value = 0;
	free(tmp->next);
	tmp->next = NULL;
	ft_lstadd_front(lst, tmp2);
	if (code == 1)
		ft_printf ("rra\n");
	else if (code == 2)
		ft_printf("rrb\n");
	return (*lst);
}
