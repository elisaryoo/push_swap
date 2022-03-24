/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 02:32:03 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/24 04:04:37 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void pushes(t_stack **stack_here, t_stack **stack_there)
{
	t_stack *push;
	t_stack *stay;
	t_stack *temp;
	
	if (!stack_here)
		return;
	else
	{
		push = stack_here;
		temp = push->next;
		
	}
		
		
		
}

void push_a(t_stack **stack_here, t_stack **stack_there, t_swap *swap)
{
	pushes(stack_here, stack_there);
		
}

void push_b(t_stack **stack_here, t_stack **stack_there, t_swap *swap)
{
	pushes(stack_here, stack_there);    
}