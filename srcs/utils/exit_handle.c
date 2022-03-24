/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 04:23:45 by eryoo             #+#    #+#             */
/*   Updated: 2022/03/24 04:38:30 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_all(t_swap *swap)
{
	free(swap->number_int);

	
}
