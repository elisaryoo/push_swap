/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:56:26 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/02 22:05:55 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		swap->current_nbr = n * s;
		return (0);
	}
}

int check_duplicate(t_swap *swap)
{
	int flag;
	int i;
	int *to_numbers;
	
	flag = 0;
	i = 0;
	while (i < swap->numbers_a)
	{
		to_numbers[i] = ft_atoi(swap->inputs[i + 1]);
		if (to_numbers[i] == swap->current_nbr)
			flag++;
		i++;
	}
	if (flag >= 2)
		return (1);
	else 
		return (0);
}

void convert_inputs(t_swap *swap)
{
	int check;
	int flag;
	
	//swap->stack_a == NULL;
	swap->max_nbr = swap->numbers_a;
	while(swap->numbers_a + 1 > 1)
	{
		check = check_range(swap->inputs[swap->numbers_a], swap);
		if (check == 1)
			error_exit();
		else 
		{
			flag = check_duplicate(swap);
			if (flag == 1)
				error_exit();
			else
				ft_lstadd_front_doubly(&(swap->stack_a), ft_lstnew_doubly(swap->current_nbr));
		}
		swap->numbers_a--;
	} 
}

void check_inputs(t_swap *swap)
{
	int i;
	int j;
	int length;

	i = 1;
	while (i < swap->numbers_a + 1)
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
