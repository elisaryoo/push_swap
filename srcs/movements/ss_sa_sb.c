/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_sa_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:30:39 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/24 04:06:45 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swaps(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*one;
	t_stack	*two;

	one = *stack;
	two = one->next;
	tmp = two->next;
	two->prev = NULL;
	two->next = NULL;
	one->prev = two;
	one->next = tmp;
	if (tmp)
		tmp->prev = one;
	two->next = one;
	*stack = two;
}

void	swap_a(t_swap *swap)
{
	swaps(&(swap->stack_a));
	write(1, "sa\n", 3);
}

void	swap_b(t_swap *swap)
{
	swaps(&(swap->stack_b));
	write(1, "sb\n", 3);
}

void	swap_both(t_swap *swap)
{
	swap_a(swap);
	swap_b(swap);
	write(1, "ss\n", 3);
}
