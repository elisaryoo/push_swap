/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:21 by eryoo             #+#    #+#             */
/*   Updated: 2022/04/03 22:56:03 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//colocar o CFLAGS NO C!!!

void print_node(t_swap *swap)
{
	t_stack *temp = swap->stack_a;

	printf("entrei no print a\n");
	if (temp == NULL)
		printf("this stack a is empty\n");
	while(temp != NULL) {
		printf("stack a is here: %d\n",temp->data);
		temp = temp->next;
	}
}

void print_index(t_swap *swap)
{
	t_stack *temp = swap->stack_a;
	while(temp != NULL) {
		printf("%d\n",temp->index);
		//printf("\n a index is here: %d",temp->index);
		temp = temp->next;
	}
}

void print_node_b(t_swap *swap)
{
	t_stack *temp = swap->stack_b;
	if (temp == NULL)
		printf("this stack b is empty\n");
	while(temp != NULL) {
		printf("stack b is here: %d",temp->data);
		printf("\n\n");
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
		conversion(&swap);
		sort(&swap);
		print_node(&swap);
		print_node_b(&swap);
		printf("the number of list is %d\n", swap.numbers_a);
		printf("the number of list is %d\n", swap.numbers_b);
		free_stack(&(swap.subst));
		free_stack(&(swap.stack_a));
	}
}
