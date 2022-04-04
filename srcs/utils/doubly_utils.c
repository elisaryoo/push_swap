/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryoo <eryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:11:55 by eryoo             #+#    #+#             */
/*   Updated: 2022/04/04 00:03:14 by eryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*ft_lstnew_doubly(int content)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	else
	{
		ptr->data = content;
		ptr->next = NULL;
		ptr->prev = NULL;
	}
	return (ptr);
}

t_stack	*ft_lstlast_doubly(t_stack *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next != NULL)
		lst = lst->next;
	if (lst->next == NULL)
		return (lst);
	return (NULL);
}

void	ft_lstadd_front_doubly(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->prev = NULL;
		new->next = *lst;
		(*lst)->prev = new;
		(*lst) = new;
	}
}

void	ft_lstadd_back_doubly(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast_doubly(*lst);
	ptr->next = new;
	new->prev = ptr;
	new->next = NULL;
}
