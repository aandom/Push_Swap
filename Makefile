# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 14:53:44 by aandom            #+#    #+#              #
#    Updated: 2023/03/24 19:57:25 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

FT_PRINTF = ./ft_printf

SRCS = $(wildcard libft/*.c) $(wildcard m_push_swap/*.c) 
		
SRCS_B = $(wildcard libft/*.c) $(wildcard p_checker/*.c) 
		
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