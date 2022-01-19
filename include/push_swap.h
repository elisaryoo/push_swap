/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:15 by eryoo             #+#    #+#             */
/*   Updated: 2022/01/18 17:20:14 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h> //take out later

typedef struct s_stack {
    int data;
    struct s_stack *next;
    struct s_stack *prev;
} t_stack;

typedef struct s_push {
    char **inputs;
    int stack_a;
    int stack_b;
    
} t_push;

void get_numbers(int argc, char **argv);


#endif