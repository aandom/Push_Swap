/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:59:01 by aandom            #+#    #+#             */
/*   Updated: 2023/03/24 15:02:41 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	put_num_to_stack_a(int ac, char **av, t_list **st_a)
{
	char	**ar;
	int		i;
	t_list	*new;
	int		code;

	i = 0;
	code = 0;
	if (ac == 2)
	{
		ar = ft_split(av[1], ' ');
		code = 1;
	}
	else
	{
		i = 1;
		ar = av;
	}
	while (ar[i])
	{
		new = ft_lstnew(ft_atoi(ar[i]));
		ft_lstadd_back(st_a, new);
		i++;
	}
	if (code == 1)
		clean(ar);
}

int	is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		if (tmp->value >= tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_repeat(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = lst;
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL)
		{
			if (tmp1->value == tmp2->value)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}
