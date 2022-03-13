/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:56:26 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/13 20:01:29 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void check_inputs(t_swap *swap)
{
	int i;
	int j;
	int length;

	i = 0;
	while (swap->numbers_a > i)
	{	
		length = ft_strlen(swap->inputs[i]);
		j = 0;
		while (j < length)
		{
			if (swap->inputs[i][j] == '-' || swap->inputs[i][j] == '+')
			{
				if(!(ft_isdigit(swap->inputs[i][j + 1])))
					error_exit();
			} 
			else if (!(ft_isdigit(swap->inputs[i][j])))
				error_exit();
			j++;
		}
		length = 0;
		i++;
	}
}

void convert_inputs(t_swap *swap)
{
	int flag;
	int counter;
	int i;
	int j;
	
	i = 0;
	j = 0;
	flag = 0;
	counter = 0;
	swap->number_int = malloc(swap->numbers_a * (sizeof(int *)));
	while(swap->numbers_a > i)
	{
		if (check_range(swap->inputs[i],swap) == 1)
			error_exit();
		counter++;
		swap->number_int[i] = swap->current_nbr;
		while (j < counter)
		{
			if (swap->number_int[j] == swap->current_nbr)
				flag++;
			j++;
		}
		j = 0;
		if (flag > swap->numbers_a)
			error_exit();
		i++;
	} 
}

int	check_range(char *str, t_swap *swap)
{
	int			s;
	long int	n;

	s = 1;
	n = 0;
	if (*str == '-')
	{
		s = s * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		n = n * 10;
		n = n + ((int)*str - 48);
		str++;
	}
	if (n > 2147483648 || (n == 2147483648 && s == 1))
		return (1);
	else
	{
		swap->current_nbr = n*s;
		return (0);
	}
}

void transfer_list(t_swap *swap)
{
	int i;

	swap->stack_a = NULL;
	i = 0;
	while (swap->number_int[i])
	{
		ft_lstadd_back_doubly(&(swap->stack_a), ft_lstnew_doubly(swap->number_int[i]));
		i++;
	}
}