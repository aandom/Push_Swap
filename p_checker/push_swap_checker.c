/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:18:47 by aandom            #+#    #+#             */
/*   Updated: 2023/03/24 19:15:52 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"
#include "get_next_line.h"
#include <stdio.h>

int	ft_strcmp(char *str1, char *str2)
{
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	if ((!*str1 && !*str2))
		return (1);
	return (0);
}

void	parallel_action(t_list **st_a, t_list **st_b, char *action)
{
	if (ft_strcmp("ss\n", action))
	{
		swap(st_a, 0);
		swap(st_b, 0);
	}
	else if (ft_strcmp("rr\n", action))
	{
		*st_a = rotate(st_a, 0);
		*st_b = rotate(st_b, 0);
	}
	else if (ft_strcmp("rrr\n", action))
	{
		*st_a = rev_rotate(st_a, 0);
		*st_b = rev_rotate(st_b, 0);
	}
	else
	{
		ft_printf("WRONG INSTRUCTION ...\n");
		ft_clean(st_b);
		ft_clean(st_a);
		free(action);
		exit(0);
	}
}

void	apply_instruction(t_list **st_a, t_list **st_b, char *action)
{
	if (ft_strcmp("ra\n", action))
		*st_a = rotate(st_a, 0);
	else if (ft_strcmp("rb\n", action))
		*st_b = rotate(st_b, 0);
	else if (ft_strcmp("sa\n", action))
		swap(st_a, 0);
	else if (ft_strcmp("pa\n", action))
		push(st_b, st_a, 3);
	else if (ft_strcmp("pb\n", action))
		push(st_a, st_b, 3);
	else if (ft_strcmp("sb\n", action))
		swap(st_b, 0);
	else if (ft_strcmp("rra\n", action))
		*st_a = rev_rotate(st_a, 0);
	else if (ft_strcmp("rrb\n", action))
		*st_b = rev_rotate(st_b, 0);
	else
		parallel_action(st_a, st_b, action);
}

int	read_instruction(t_list **st_a, t_list **st_b)
{
	char	*line;
	int		fd;
	int		c;

	c = 0;
	fd = 0;
	line = NULL;
	if (is_sorted(*st_a))
		c++;
	while (1)
	{
		line = get_next_line(fd);
		if ((ft_strcmp(line, "done\n") == 0) && c == 1)
			c = 2;
		else if (ft_strcmp(line, "done\n") != 0)
		{
			free(line);
			break ;
		}
		apply_instruction(st_a, st_b, line);
		free(line);
	}
	if (c == 2)
		return (0);
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
		if (read_instruction(&st_a, &st_b) > 0 && is_sorted(st_a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	ft_clean(&st_b);
	ft_clean(&st_a);
	return (0);
}
