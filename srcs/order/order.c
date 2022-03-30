/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:10:15 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/29 22:58:30 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_list(t_swap *swap)
{
	int	i;
	int	j;
	int	tmp;
	int	length;
	
	length = swap->numbers_a;
	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length - 1)
		{
			if (swap->number_int[j] > swap->number_int[j + 1])
			{
				tmp = swap->number_int[j];
				swap->number_int[j] = swap->number_int[j + 1];
				swap->number_int[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	index_list(t_swap *swap, t_stack **stack_a)
{
	int	i;
	int	length;
	t_stack *stack;

	length = swap->numbers_a;
	i = 0;
	while (i < length )
	{
		stack = (*stack_a);
		while (stack != NULL)
		{
			if (swap->number_int[i] == stack->data)
			{
				stack->index = i;
				//stack->data = i;
				break ;
			}
			stack = stack->next;
		}
		i++;
	}
}

void	order(t_swap *swap)
{
	// int x = 0;
	// while (swap->number_int[x])
	// {	
	// 	printf("before %d\n", swap->number_int[x]);
	// 	x++;
	// }
	sort_list(swap);
	index_list(swap, &(swap->stack_a));
}
