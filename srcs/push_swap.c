/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:21 by eryoo             #+#    #+#             */
/*   Updated: 2022/04/03 23:41:30 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	swap;

	swap.numbers_a = argc - 1;
	swap.inputs = argv + 1;
	swap.numbers_b = 0;
	if (swap.numbers_a <= 1)
		return (1);
	else
	{
		init_stacks(&swap);
		check_inputs(&swap);
		conversion(&swap);
		sort(&swap);
		free_stack(&(swap.subst));
		free_stack(&(swap.stack_a));
		free_stack(&(swap.stack_b));
	}
	return (0);
}
