/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 04:23:45 by eryoo             #+#    #+#             */
/*   Updated: 2022/04/03 23:15:36 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_stacks(t_swap *swap)
{
	swap->stack_a = NULL;
	swap->stack_b = NULL;
	swap->subst = NULL;
}

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack) == NULL)
		return ;
	while ((*stack) != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		(*stack) = temp;
	}
}
