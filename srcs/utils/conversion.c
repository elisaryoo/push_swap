/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:56:26 by eryoo             #+#    #+#             */
/*   Updated: 2022/04/04 00:06:41 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	check_inputs(t_swap *swap)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	while (swap->numbers_a > i)
	{	
		length = ft_strlen(swap->inputs[i]);
		j = 0;
		while (j < length)
		{
			if (swap->inputs[i][j] == '-' || swap->inputs[i][j] == '+')
			{
				if (!(ft_isdigit(swap->inputs[i][j + 1])))
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

int	check_duplicate(t_stack **stack, t_swap *swap)
{
	int		flag;
	t_stack	*tmp;

	flag = 0;
	tmp = (*stack);
	while (tmp->next != NULL)
	{
		if (tmp->data == swap->current_nbr)
			flag++;
		tmp = tmp->next;
	}
	return (flag);
}

void	conversion(t_swap *swap)
{
	int	i;

	i = 0;
	while (swap->numbers_a > i)
	{
		if (check_range(swap->inputs[i], swap) != 1)
		{
			ft_lstadd_back_doubly(&(swap->subst), \
			ft_lstnew_doubly(swap->current_nbr));
		}
		else
			error_exit();
		if (check_duplicate(&(swap->subst), swap) > 0)
			error_exit();
		ft_lstadd_back_doubly(&(swap->stack_a), \
			ft_lstnew_doubly(swap->current_nbr));
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
		swap->current_nbr = n * s;
		return (0);
	}
}
