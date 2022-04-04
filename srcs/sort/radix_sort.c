/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:43:00 by eryoo             #+#    #+#             */
/*   Updated: 2022/04/03 23:46:45 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	radix_sort(t_stack **stack_a, t_swap *swap)
{
	int		i;
	int		j;
	int		bits;
	int		size;
	t_stack	*list;

	i = -1;
	size = swap->numbers_a;
	list = (*stack_a);
	bits = into_bits(&list);
	while (++i < bits)
	{
		j = -1;
		while (++j < size)
		{
			list = (*stack_a);
			if (((list->index >> i) & 1) == 1)
				rotate_a(swap);
			else
				push_b(&(swap->stack_a), &(swap->stack_b), swap);
		}
		while (swap->numbers_b != 0)
			push_a(&(swap->stack_a), &(swap->stack_b), swap);
	}
}

int	into_bits(t_stack **stack)
{
	int		max;
	int		max_bit;
	t_stack	*head;

	head = (*stack);
	max = head->index;
	max_bit = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

int	min_value(t_stack **stack)
{
	int		min;
	t_stack	*tmp;

	tmp = (*stack);
	min = 0;
	if (tmp)
	{
		min = tmp->data;
		while (tmp != NULL)
		{
			if (tmp->data < min)
				min = tmp->data;
			tmp = tmp->next;
		}
	}
	return (min);
}
