/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:26:19 by aandom            #+#    #+#             */
/*   Updated: 2023/03/24 19:20:49 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	sort_three(t_list **st_a);
void	sort_four(t_list **st_a, t_list **st_b, int max);
void	sort_five(t_list **st_a, t_list **st_b, t_array array);
void	quik_sort(t_list **st_a, t_list **st_b, t_array *array);
void	med_array(t_list **lst, t_array *array);
int		findmax(t_list **lst);
void	sort_arr(t_array *array);
void	index_stack(t_list **lst, t_array *array);
void	big_sort(t_list **st_a, t_list **st_b, t_array *array);
void	target_pos(t_list **st_a, t_list **st_b);
void	find_cost(t_list **lst1, t_list **lst2);
void	shortest_move(t_list **lst1, t_list **lst2);
void	cur_position(t_list **lst);
int		get_tar_pos(t_list **lst, int n_index, int tar_index, int tar_pos);
void	target_pos(t_list **st_a, t_list **st_b);
void	shortest_move(t_list **lst1, t_list **lst2);
void	multi_rotate(t_list **lst, int *cost, int code);
void	ra_and_rb(t_list **st_a, t_list **st_b, int *c_a, int *c_b);
void	rra_and_rrb(t_list **st_a, t_list **st_b, int *c_a, int *c_b);
void	shift_st_a(t_list **st_a);

#endif