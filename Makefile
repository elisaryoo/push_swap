# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eryoo <eryoo@student.42sp.org.br>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 07:09:18 by eryoo             #+#    #+#              #
#    Updated: 2022/01/12 19:28:39 by eryoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = 		/bin/rm -f
LIBFT_PATH = libft
LIBFT =		$(LIBFT_PATH)/libft.a

INCLUDE = include/push_swap.h

SRCS = srcs/push_swap.c \
		
OBJS = $(SRCS:.c=.o)

all: $(NAME) $(INCLUDE)

$(NAME): 	$(OBJS) $(LIBFT)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -g $(LIBFT)

$(LIBFT):
		@make -C $(LIBFT_PATH)

clean:
			@$(RM) $(OBJS)
			@make clean -C $(LIBFT_PATH)

fclean:		clean
			@$(RM) $(NAME) $(OBJS)
			make fclean -C $(LIBFT_PATH)

norminette: 
			norminette libft srcs include 

re: fclean all

.PHONY:		all clean fclean re