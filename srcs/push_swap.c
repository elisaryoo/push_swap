/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:21 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/13 20:02:30 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//colocar o CFLAGS NO C!!!

void print_node(t_swap *swap)
{
	t_stack *temp = swap->stack_a;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void free_all(t_swap *swap)
{
	
}

int	main(int argc, char **argv)
{
	t_swap swap;

	swap.numbers_a = argc - 1; 
	swap.inputs = argv + 1;
	if (swap.numbers_a <= 1)
		error_exit();
	else 
	{
		check_inputs(&swap);
		convert_inputs(&swap);
		transfer_list(&swap);
		print_node(&swap);
		//free_all(&swap);
	}
}
