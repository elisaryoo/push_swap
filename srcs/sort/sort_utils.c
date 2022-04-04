/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:08:19 by eryoo             #+#    #+#             */
/*   Updated: 2022/04/03 19:08:43 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	min_value(t_stack **stack)
{
	int min;
	t_stack *tmp;
	
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
