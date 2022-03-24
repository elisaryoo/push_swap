/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:21 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/24 04:36:19 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//colocar o CFLAGS NO C!!!

void print_node(t_swap *swap)
{
	t_stack *temp = swap->stack_a;
	while(temp != NULL) {
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_swap	swap;

	swap.numbers_a = argc - 1;
	swap.inputs = argv + 1;
	if (swap.numbers_a <= 1)
		error_exit();
	else
	{
		check_inputs(&swap);
		convert_inputs(&swap);
		free_all(&swap);
		printf("okay");
		//transfer_list(&swap);
		//swap_a(&swap);
		//reverse_a(&swap);
		//rotate_a(&swap);
		//print_node(&swap);
		//start_sort
		//free_all(&swap);
	}
}
