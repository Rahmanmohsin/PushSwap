/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 01:37:54 by mohrahma          #+#    #+#             */
/*   Updated: 2024/04/19 04:26:46 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_spec(t_ps_list **list, int c)
{
	t_ps_list	*top;
	t_ps_list	*next;

	top = (*list);
	next = (*list)->next;
	next->next = top;
	top->prev = next;
	next->prev = NULL;
	top->next = NULL;
	(*list) = next;
	if (c == 1)
		write(1, "sa\n", 3);
	else if (c == 2)
		write(1, "sb\n", 3);
	else
		write(1, "ss\n", 3);
}

void	swap(t_ps_list **list, int c)
{
	t_ps_list	*top;
	t_ps_list	*next;
	t_ps_list	*temp;

	if (ft_lstsize(*list) == 2)
		return (swap_spec(list, c));
	top = (*list);
	next = (*list)->next;
	temp = next->next;
	top->next = next->next;
	top->prev = next;
	next->prev = NULL;
	next->next = top;
	temp->prev = top;
	(*list) = next;
	if (c == 1)
		write(1, "sa\n", 3);
	else if (c == 2)
		write(1, "sb\n", 3);
	else
		write(1, "ss\n", 3);
}
