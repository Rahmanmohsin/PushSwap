/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:39:07 by mohrahma          #+#    #+#             */
/*   Updated: 2024/04/19 04:26:39 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_ps_list **list, int c)
{
	t_ps_list	*head;
	t_ps_list	*tail;
	t_ps_list	*temp;

	head = (*list);
	tail = head;
	while (tail->next != NULL)
		tail = tail->next;
	temp = tail->prev;
	tail->next = head;
	head->prev = tail;
	tail->prev = NULL;
	temp->next = NULL;
	(*list) = tail;
	if (c == 1)
		write(1, "rra\n", 4);
	else if (c == 2)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}
