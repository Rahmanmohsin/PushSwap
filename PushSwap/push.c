/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 01:46:21 by mohrahma          #+#    #+#             */
/*   Updated: 2024/04/19 08:00:16 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_list_b(t_ps_list **list_b, t_ps_list **list_a)
{
	t_ps_list	*current;

	if ((*list_b))
	{
		current = (*list_b);
		current->next = (*list_a);
		(*list_a)->prev = current;
		(*list_a) = current;
	}
	else
		(*list_b) = NULL;
}

void	push_list_a(t_ps_list *list_a, t_ps_list **list_b)
{
	t_ps_list	*current;

	if (!(*list_b))
	{
		current = list_a;
		(*list_b) = current;
		(*list_b)->next = NULL;
		(*list_b) = current;
	}
	else
	{
		current = list_a;
		current->next = (*list_b);
		(*list_b)->prev = current;
		(*list_b) = current;
	}
}

void	push(t_ps_list **list_a, t_ps_list **list_b, int c)
{
	t_ps_list	*temp;
	t_ps_list	*next;

	if (c == 1)
	{
		temp = (*list_a);
		next = (*list_a)->next;
		push_list_a(temp, list_b);
		(*list_a) = next;
		write(1, "pb\n", 3);
	}
	else
	{
		if (!(*list_b))
			return ;
		temp = (*list_b);
		next = (*list_b)->next;
		push_list_b(&*list_b, &*list_a);
		(*list_b) = next;
		(*list_a) = temp;
		write(1, "pa\n", 3);
	}
}
