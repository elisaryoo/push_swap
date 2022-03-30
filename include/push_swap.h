/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:15 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/29 23:04:23 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h> //take out later

typedef struct s_stack{
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
}	t_stack;

typedef struct s_swap{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**inputs;
	int		flag;
	int		counter;
	int		max_nbr;
	int		numbers_a;
	int		numbers_b;
	int		current_nbr;
	int		*number_int;
}	t_swap;

int		check_range(char *str, t_swap *swap);
void	parse_inputs(t_swap *swap);
void	check_inputs(t_swap *swap);
void	convert_inputs(t_swap *swap);
void	transfer_list(t_swap *swap);
void	error_exit(void);
void	transfer_nbr(int number, t_swap *swap);
void	init_stacks(t_swap *swap);
void	free_stack(t_stack **stack);

void	order(t_swap *swap);
void	sort_list(t_swap *swap);
void	index_list(t_swap *swap, t_stack **stack_a);

void	ft_lstadd_front_doubly(t_stack **lst, t_stack *new);
void	ft_lstadd_back_doubly(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew_doubly(int content, t_swap *swap);
t_stack	*ft_lstlast_doubly(t_stack *lst);

void	print_node(t_swap *swap); //take this out later

void	swap_a(t_swap *swap);
void	swap_b(t_swap *swap);
void	swaps(t_stack **stack);
void	swap_both(t_swap *swap);

void	rotates(t_stack **stack);
void	rotate_a(t_swap *swap);
void	rotate_b(t_swap *swap);
void	rotate_both(t_swap *swap);

void	reverses(t_stack **stack);
void	reverse_a(t_swap *swap);
void	reverse_b(t_swap *swap);
void	reverse_both(t_swap *swap);

t_stack *transfer_to(t_stack **stack_rmv);
void pushes(t_stack **stack_add, t_stack **stack_rmv);
void push_a(t_stack **stack_add, t_stack **stack_rmv, t_swap *swap);
void push_b(t_stack **stack_rmv, t_stack **stack_add, t_swap *swap);

#endif