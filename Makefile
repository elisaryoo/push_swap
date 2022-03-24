# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 07:09:18 by eryoo             #+#    #+#              #
#    Updated: 2022/03/24 04:42:09 by eryoo            ###   ########.fr        #
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
		srcs/utils/conversion.c \
		srcs/utils/doubly_utils.c \
		srcs/utils/exit_handle.c \
		srcs/movements/ss_sa_sb.c \
		srcs/movements/rr_ra_rb.c \
		srcs/movements/rrr_rra_rrb.c \
		
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