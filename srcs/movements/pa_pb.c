/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 02:32:03 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/29 02:20:25 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*transfer_to(t_stack **stack_rmv)
{
	t_stack	*frst;
	t_stack	*scnd;
	t_stack	*new;

	frst = (*stack_rmv);
	scnd = frst->next;
	scnd->prev = NULL;
	(*stack_rmv) = scnd;
	frst->prev = NULL;
	frst->next = NULL;
	new = frst;
	return (new);
}

void	pushes(t_stack **stack_add, t_stack **stack_rmv)
{
	t_stack	*new;

	if (!*stack_rmv)
		return ;
	if (!(*stack_rmv)->next)
	{
		new = *stack_rmv;
		*stack_rmv = NULL;
	}
	else
		new = transfer_to(stack_rmv);
	new->next = *stack_add;
	if ((*stack_add) != NULL)
		(*stack_add)->prev = new;
	(*stack_add) = new;
}

void	push_a(t_stack **stack_add, t_stack **stack_rmv, t_swap *swap)
{
	pushes(stack_add, stack_rmv);
	write(1, "pa\n", 3);
	swap->numbers_b--;
	swap->numbers_a++;
}

void	push_b(t_stack **stack_rmv, t_stack **stack_add, t_swap *swap)
{
	pushes(stack_add, stack_rmv);
	write(1, "pb\n", 3);
	swap->numbers_a--;
	swap->numbers_b++;
}
