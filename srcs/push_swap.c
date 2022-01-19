/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:09:21 by eryoo             #+#    #+#             */
/*   Updated: 2022/01/18 17:33:12 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void get_numbers(int argc, char **argv)
{
	printf("%d\n", argc);
	printf("%s\n", argv[1]);
}

int	main(int argc, char **argv)
{
	t_push push;
	if (argc < 3)
	{
		write(1, "Invalid number of arguments, try again\n", 41);
		exit(1);
	}
	else 
	{
		push.stack_a = argc - 1;
		printf("%d\n", push.stack_a);
		get_numbers(argc, argv);
	}
		

}