/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:21 by eryoo             #+#    #+#             */
/*   Updated: 2022/02/01 20:23:51 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//colocar o CFLAGS NO C!!!
int check_range(t_swap *swap)
{
	long int num;
	int length;
	//-2147483648
	//2147483647
	length =  ft_strlen(swap->inputs[swap->x]);
	printf("%s", swap->inputs[swap->x]);
	if (swap->inputs[swap->x][0] == 45)
	{
		if (length > 10 && swap->inputs[swap->x][10] > 57)
		{
			printf("nope3");
			return (1);
		}
	}
	if (length > 9 && swap->inputs[swap->x][9] > 56)
	{
		printf("nope4");
		return (1);
	}
	return (0);
}

void convert_inputs(t_swap *swap)
{
	int i;
	int check;
	// int temp;

	i = 1;
	while(swap->numbers_a >= i)
	{
		printf("%s\n", swap->inputs[0]);
		check = check_range(swap);
		if (check == 1)
		{
			exit(1);
		}
		else 
			printf("Hello!");
			//temp = ft_atoi(swap->inputs[i]);
		swap->numbers_a--;
	} 
}

void check_inputs(t_swap *swap)
{
	int i;
	int j;
	int length;
	int check;

	i = 1;
	while (i < swap->numbers_a + 1)
	{	
		length = ft_strlen(swap->inputs[i]);
		//printf("%s\n", swap->inputs[i]);
		//printf("%d\n", length);
		j = 0;
		while (j < length)
		{
			//printf("%c\n", swap->inputs[i][j]);
			if (swap->inputs[i][j] == '-' || swap->inputs[i][j] == '+')
			{
				if(!(ft_isdigit(swap->inputs[i][j + 1])))
				{
				printf("nope1");
				exit(1);
				}
			} 
			else if (!(ft_isdigit(swap->inputs[i][j])))
			{
				printf("nope2");
				exit(1);
			}
			j++;
		}
		length = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_swap swap;

	swap.numbers_a = argc - 1;
	swap.inputs = argv;
	if (swap.numbers_a < 1)
	{
		write(1, "There seems to be only one argument here", 41);
		exit(1);
	}
	else 
	{
		check_inputs(&swap);
		convert_inputs(&swap);

	}
	//printf("%d", swap.numbers_a);

}