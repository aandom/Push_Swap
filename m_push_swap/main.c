/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:06:49 by aandom            #+#    #+#             */
/*   Updated: 2023/03/02 20:06:49 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_nums(t_list **st_a, t_list **st_b)
{
	t_array	*array;

	array = (t_array *) malloc(sizeof(t_array));
	if (!array)
		return ;
	med_array(st_a, array);
	index_stack(st_a, array);
	if (array->len <= 5)
		quik_sort(st_a, st_b, array);
	else if (array->len <= 500)
	{
		big_sort(st_a, st_b, array);
	}
	free(array->arr);
	free(array);
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

int	main(int ac, char **av)
{
	t_list	*st_a;
	t_list	*st_b;

	st_a = NULL;
	st_b = NULL;
	if (ac < 2)
		return (0);
	if (ft_check_args(ac, av) == 0)
		write(2, "Error\n", 6);
	else
	{
		put_num_to_stack_a(ac, av, &st_a);
		if (!check_repeat(st_a))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (!is_sorted(st_a))
			sort_nums(&st_a, &st_b);
		if (!is_sorted(st_a))
			shift_st_a(&st_a);
	}
	ft_clean(&st_b);
	ft_clean(&st_a);
	return (0);
}
