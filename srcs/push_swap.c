/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:21 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/02 21:58:20 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//colocar o CFLAGS NO C!!!


void print_me(t_swap *swap)
{
	while (swap->stack_a != NULL)
	{
		printf("%d!!!\n", swap->stack_a->data);
		swap->stack_a = swap->stack_a->next;
	}
}

void displayList(t_swap *swap) {
  struct Node* last;

  while (swap->stack_a != NULL) {
    printf("%d->", swap->stack_a->data);
    last = swap->stack_a;
    swap->stack_a = swap->stack_a->next;
  }
  if (swap->stack_a == NULL)
    printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_swap swap;

	swap.numbers_a = argc - 1; 
	swap.inputs = argv;
	if (swap.numbers_a <= 1)
		error_exit();
	else 
	{
		check_inputs(&swap);
		convert_inputs(&swap);
		print_me(&swap);
	}
}
