/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:15 by eryoo             #+#    #+#             */
/*   Updated: 2022/04/03 22:55:23 by eryoo            ###   ########.fr       */
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
	t_stack	*subst;
	char	**inputs;
	int		flag;
	int		counter;
	int		max_nbr;
	int		numbers_a;
	int		numbers_b;
	int		current_nbr;
}	t_swap;

int		check_range(char *str, t_swap *swap);
void	parse_inputs(t_swap *swap);
void	check_inputs(t_swap *swap);
void	error_exit(void);
void	transfer_nbr(int number, t_swap *swap);
void	init_stacks(t_swap *swap);
void	free_stack(t_stack **stack);

void	sort(t_swap *swap);
void	sort_array(t_stack **stack, t_swap *swap);
void	sort_list(int **array, t_swap *swap);
void	index_list(int **array, t_stack **stack_a, t_swap *swap);
int		not_sorted(t_stack **stack_a);

void	case_two(t_stack **stack_a, t_swap *swap);
void	case_three(t_stack **stack_a, t_swap *swap);
void	case_four(t_stack **stack_a, t_swap *swap);
void	case_five(t_stack **stack_a, t_swap *swap);

void	smaller_cases(t_stack **stack_a, t_swap *swap);
int		min_value(t_stack **stack);

void	ft_lstadd_front_doubly(t_stack **lst, t_stack *new);
void	ft_lstadd_back_doubly(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew_doubly(int content, t_swap *swap);
t_stack	*ft_lstlast_doubly(t_stack *lst);

void	print_node(t_swap *swap); //take this out later
void print_index(t_swap *swap);
void print_node_b(t_swap *swap);
void	conversion(t_swap *swap);
int		check_duplicate(t_stack **stack, t_swap *swap);

void	radix_sort(t_stack **stack_a, t_swap *swap);
int into_bits(t_stack **stack);

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