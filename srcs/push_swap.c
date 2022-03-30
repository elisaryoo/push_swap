/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:21 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/29 23:06:41 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//colocar o CFLAGS NO C!!!

void print_node(t_swap *swap)
{
	t_stack *temp = swap->stack_a;
	while(temp != NULL) {
		printf("\n a is here: %d",temp->data);
		temp = temp->next;
	}
}

void print_index(t_swap *swap)
{
	t_stack *temp = swap->stack_a;
	while(temp != NULL) {
		printf("\n a is here: %d",temp->data);
		printf("\n a index is here: %d",temp->index);
		temp = temp->next;
	}
}

void print_node_b(t_swap *swap)
{
	t_stack *temp = swap->stack_b;
	while(temp != NULL) {
		printf("%d",temp->data);
		printf("\n");
		temp = temp->next;
	}
	
}

int	main(int argc, char **argv)
{
	t_swap	swap;

	swap.numbers_a = argc - 1;
	swap.inputs = argv + 1;
	swap.numbers_b = 0;
	if (swap.numbers_a <= 1)
		error_exit();
	else
	{
		init_stacks(&swap);
		check_inputs(&swap);
		convert_inputs(&swap);
		transfer_list(&swap);
		printf("%d and %d\n", swap.numbers_b, swap.numbers_a);
		order(&swap);
		print_index(&swap);
		free(swap.number_int);
		free_stack(&(swap.stack_a));
		free_stack(&(swap.stack_b));
	}
}
