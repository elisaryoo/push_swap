/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_2_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:43:27 by eryoo             #+#    #+#             */
/*   Updated: 2022/04/03 19:12:37 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	smaller_cases(t_stack **stack_a, t_swap *swap)
{
	if ((*stack_a)->next->next->data > (*stack_a)->next->data && \
	(*stack_a)->next->next->data > (*stack_a)->data)
		swap_a(swap);
	else if ((*stack_a)->next->next->data < \
	(*stack_a)->next->data && (*stack_a)->next->next->data < \
	(*stack_a)->data)
	{
		swap_a(swap);
		reverse_a(swap);
	}
	else if ((*stack_a)->next->next->data > \
	(*stack_a)->next->data && \
	(*stack_a)->next->next->data < (*stack_a)->data)
		rotate_a(swap);
}

void	case_two(t_stack **stack_a, t_swap *swap)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		swap_a(swap);
}

void	case_three(t_stack **stack_a, t_swap *swap)
{
	if ((*stack_a)->data < (*stack_a)->next->data && \
	(*stack_a)->next->data < (*stack_a)->next->next->data)
		return ;
	if ((*stack_a)->next->data < (*stack_a)->data)
		smaller_cases(&(swap->stack_a), swap);
	else if((*stack_a)->data < (*stack_a)->next->data)
	{
		if ((*stack_a)->data < (*stack_a)->next->next->data && \
		(*stack_a)->next->data > (*stack_a)->next->next->data)
		{
			swap_a(swap);
			rotate_a(swap);
		}
		else
			reverse_a(swap);
	}
}

void	case_four(t_stack **stack_a, t_swap *swap)
{
	int min;
	t_stack *list;
	
	list = (*stack_a);
	min = min_value(&(swap->stack_a));
	while (list != NULL)
	{
		if (list->data == min)
		{
			push_b(&(swap->stack_a), &(swap->stack_b), swap);
			break;
		}
		list = list->next;
		rotate_a(swap);
	}
	case_three(&(swap->stack_a), swap);
	push_a(&(swap->stack_a), &(swap->stack_b), swap);
}

void	case_five(t_stack **stack_a, t_swap *swap)
{
	int min;
	t_stack *list;

	list = (*stack_a);
	min = min_value(&(swap->stack_a));
	while (list != 	NULL)
	{
		if (list->data == min)
		{
			push_b(&(swap->stack_a), &(swap->stack_b), swap);
			break;
		}
		list = list->next;
		rotate_a(swap);
	}
	case_four(&(swap->stack_a), swap);
	push_a(&(swap->stack_a), &(swap->stack_b), swap);
}
