/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_rra_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:31:25 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/24 04:06:11 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverses(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	last = *stack;
	while (last->next->next)
		last = last->next;
	first = last->next;
	last->next = NULL;
	first->prev = NULL;
	first->next = *stack;
	(*stack)->prev = first;
	*stack = first;
}

void	reverse_a(t_swap *swap)
{
	reverses(&(swap->stack_a));
	write(1, "rra\n", 4);
}

void	reverse_b(t_swap *swap)
{
	reverses(&(swap->stack_b));
	write(1, "rrb\n", 4);
}

void	reverse_both(t_swap *swap)
{
	reverse_a(swap);
	reverse_b(swap);
	write(1, "rrr\n", 4);
}
