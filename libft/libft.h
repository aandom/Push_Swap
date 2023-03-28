/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:18:36 by aandom            #+#    #+#             */
/*   Updated: 2023/03/24 19:18:02 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				c_a;
	int				c_b;
	int				t_pos;
	int				len;
	struct s_list	*next;
}					t_list;

typedef struct s_array
{
	int		*arr;
	int		arr_max;
	int		arr_min;
	int		med;
	int		len;
}			t_array;

char	**ft_split(char *str, char c);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	swap(t_list **lst, int code);
void	push(t_list **lst1, t_list **lst2, int code);
t_list	*rotate(t_list **lst, int code);
t_list	*rev_rotate(t_list **lst, int code);
int		ft_check_args(int ac, char **av);
int		is_sorted(t_list *lst);
int		is_all_digit(char *s);
void	ft_clean(t_list **lst);
char	**clean(char **av);

#endif