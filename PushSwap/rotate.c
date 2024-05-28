/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:35:34 by mohrahma          #+#    #+#             */
/*   Updated: 2024/04/19 04:26:42 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_ps_list **list, int c)
{
	t_ps_list	*head;
	t_ps_list	*tail;

	head = (*list);
	tail = head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = head;
	head->prev = tail;
	(*list) = head->next;
	head->next = NULL;
	(*list)->prev = NULL;
	if (c == 1)
		write(1, "ra\n", 3);
	else if (c == 2)
		write(1, "rb\n", 3);
	else
		write(1, "rr\n", 3);
}
