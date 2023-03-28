/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:00:13 by aandom            #+#    #+#             */
/*   Updated: 2023/03/24 19:21:44 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include "../libft/libft.h"
# include "get_next_line.h"

int		is_all_digit(char *s);
int		check_repeat(t_list *lst);
int		is_sorted(t_list *lst);
void	put_num_to_stack_a(int ac, char **av, t_list **st_a);

#endif