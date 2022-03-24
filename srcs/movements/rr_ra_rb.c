/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ra_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:31:17 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/24 04:07:34 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotates(t_stack **stack)
{
	t_stack	*one;
	t_stack	*final;

	one = (*stack)->next;
	one->prev = NULL;
	final = ft_lstlast_doubly(*stack);
	final->next = *stack;
	(*stack)->prev = final;
	(*stack)->next = NULL;
	*stack = one;
}

void	rotate_a(t_swap *swap)
{
	rotates(&(swap->stack_a));
	write(1, "ra\n", 3);
}

void	rotate_b(t_swap *swap)
{
	rotates(&(swap->stack_b));
	write(1, "rb\n", 3);
}

void	rotate_both(t_swap *swap)
{
	rotate_a(swap);
	rotate_b(swap);
	write(1, "rr\n", 3);
}
