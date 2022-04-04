/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:10:15 by eryoo             #+#    #+#             */
/*   Updated: 2022/04/03 22:55:30 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_array(t_stack **stack_a, t_swap *swap)
{
	int		i;
	int		*array;
	t_stack	*tmp;

	i = 0;
	array = (int *)malloc(swap->numbers_a * sizeof(int));
	if (!array)
		error_exit();
	tmp = (*stack_a);
	while (tmp != NULL)
	{
		array[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	sort_list(&array, swap);
	index_list(&array, &(swap->stack_a), swap);
	free(array);
}

void	sort_list(int **array, t_swap *swap)
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
			if ((*array)[j] > (*array)[j + 1])
			{
				tmp = (*array)[j];
				(*array)[j] = (*array)[j + 1];
				(*array)[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	index_list(int **array, t_stack **stack_a, t_swap *swap)
{
	int		i;
	int		length;
	t_stack	*stack;

	length = swap->numbers_a;
	i = 0;
	while (i < length)
	{
		stack = (*stack_a);
		while (stack != NULL)
		{
			if ((*array)[i] == stack->data)
			{
				stack->index = i;
				break ;
			}
			stack = stack->next;
		}
		i++;
	}
}

int	not_sorted(t_stack **stack_a)
{
	int		flag;
	t_stack	*frst;
	t_stack	*scnd;

	flag = 0;
	frst = (*stack_a);
	scnd = (*stack_a);
	while (scnd->next != NULL)
	{
		scnd = scnd->next;
		if (frst->index > scnd->index)
		{
			flag = 1;
			break ;
		}
		frst = frst->next;
	}
	return (flag);
}

void	sort(t_swap *swap)
{
	sort_array(&(swap->stack_a), swap);
	if (not_sorted(&(swap->stack_a)) == 0)
		return ;
	else if (swap->numbers_a == 2)
		case_two(&(swap->stack_a), swap);
	else if (swap->numbers_a == 3)
		case_three(&(swap->stack_a), swap);
	else if (swap->numbers_a == 4)
		case_four(&(swap->stack_a), swap);
	else if (swap->numbers_a == 5)
		case_five(&(swap->stack_a), swap);
	else
		radix_sort(&(swap->stack_a), swap);
}
