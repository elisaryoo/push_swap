/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:15 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/13 20:01:45 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h> //take out later

typedef struct s_stack {
    int data;
    struct s_stack *next;
    struct s_stack *prev;
} t_stack;

typedef struct s_swap {
    t_stack *stack_a;
    char **inputs;
    int current_nbr;
    int *number_int;
    int flag;
    int numbers_a;
    int max_nbr;
} t_swap;

void parse_inputs(t_swap *swap);
int check_range(char *str, t_swap *swap);
void check_inputs(t_swap *swap);
void convert_inputs(t_swap *swap);
void transfer_list(t_swap *swap);
void error_exit(void);
void transfer_nbr(int number, t_swap *swap);
t_stack    *ft_lstnew_doubly(int content);
t_stack    *ft_lstlast_doubly(t_stack *lst);
void    ft_lstadd_front_doubly(t_stack **lst, t_stack *new);
void    ft_lstadd_back_doubly(t_stack **lst, t_stack *new);
void print_node(t_swap *swap);
#endif