# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 14:53:44 by aandom            #+#    #+#              #
#    Updated: 2024/11/09 14:46:27 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

FT_PRINTF = ./ft_printf

LIBFT = libft/check.c libft/ft_atoi.c libft/ft_free.c libft/ft_isdigit.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstlast.c \
	   libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_split.c libft/operations.c

# SRCS = $(wildcard libft/*.c) $(wildcard m_push_swap/*.c)
SRCS = $(LIBFT) m_push_swap/action.c m_push_swap/big_sort.c m_push_swap/main.c m_push_swap/position.c m_push_swap/shift.c m_push_swap/small_sort.c \
		m_push_swap/take_action.c m_push_swap/utils.c
		
		
# SRCS_B = $(wildcard libft/*.c) $(wildcard p_checker/*.c) 
SRCS_B = $(LIBFT) p_checker/get_next_line.c p_checker/get_next_line_utils.c p_checker/push_swap_checker.c p_checker/validate.c
		
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
CFLAGS = -Wextra -Werror -Wall
CC = cc

$(NAME): $(OBJS)
		 $(MAKE) -C $(FT_PRINTF)
		 $(CC) $(CFLAGS) $(OBJS) ft_printf/libftprintf.a -o $(NAME)

$(NAME_B): $(OBJS_B)
		 $(MAKE) -C $(FT_PRINTF)
		 $(CC) $(CFLAGS) $(OBJS_B) ft_printf/libftprintf.a -o $(NAME_B)

all: $(NAME)

bonus: $(NAME_B)

clean: 
		$(MAKE) clean -C $(FT_PRINTF)
		rm -f $(OBJS_B)
		rm -f $(OBJS)

fclean: clean
		rm -f ft_printf/libftprintf.a
		rm -f $(NAME)
		rm -f $(NAME_B)

re: fclean	$(NAME)

.PHONY: all clean fclean re