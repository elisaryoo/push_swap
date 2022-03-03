# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 07:09:18 by eryoo             #+#    #+#              #
#    Updated: 2022/03/02 18:44:31 by eryoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = 		/bin/rm -f
LIBFT_PATH = libft
LIBFT =		$(LIBFT_PATH)/libft.a

INCLUDE = include/push_swap.h

SRCS = srcs/push_swap.c \
		srcs/conversion.c \
		srcs/push_swap_utils.c \
		
OBJS = $(SRCS:.c=.o)

all: $(NAME) $(INCLUDE)

$(NAME): 	$(OBJS) $(LIBFT)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJS) -g $(LIBFT)

$(LIBFT):
		@make bonus -C $(LIBFT_PATH)

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