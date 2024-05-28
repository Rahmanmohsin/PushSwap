/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:08:41 by mohrahma          #+#    #+#             */
/*   Updated: 2024/04/23 16:04:30 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_three(t_ps_list **lst)
{
	t_ps_list	*top;
	t_ps_list	*mid;
	t_ps_list	*last;

	last = (*lst);
	top = last;
	mid = last->next;
	last = mid->next;
	if (top->index < last->index && top->index < mid->index
		&& mid->index > last->index)
		return (swap(lst, 1), rotate(lst, 1));
	else if (top->index > last->index && top->index > mid->index
		&& mid->index > last->index)
		return (swap(lst, 1), reverse_rotate(lst, 1));
	else if (top->index > mid->index && top->index < last->index
		&& mid->index < last->index)
		return (swap(lst, 1));
	else if (top->index < mid->index && top->index > last->index
		&& mid->index > last->index)
		return (reverse_rotate(lst, 1));
	else if (top->index > last->index && top->index > mid->index
		&& mid->index < last->index)
		return (rotate(lst, 1));
}

void	algorithm_five_pt2(t_ps_list **list_a, t_ps_list **list_b)
{
	if ((*list_a)->index > 3)
		while ((*list_a)->index + 1 != (*list_b)->index
			&& (*list_a)->index - 1 != (*list_b)->index)
			reverse_rotate(list_a, 1);
	else
		while ((*list_a)->index + 1 != (*list_b)->index
			&& (*list_a)->index - 1 != (*list_b)->index)
			rotate(list_a, 1);
	if ((*list_a)->index > (*list_b)->index)
		push(list_a, list_b, 2);
	else
	{
		rotate(list_a, 1);
		push(list_a, list_b, 2);
	}
}

void	algorithm_finish(t_ps_list **list_a, int c)
{
	if ((*list_a)->index > 3 && c == 5)
		while ((*list_a)->index != 1)
			rotate(list_a, 1);
	else if ((*list_a)->index > 2 && c == 4)
		while ((*list_a)->index != 1)
			rotate(list_a, 1);
	else
		while ((*list_a)->index != 1)
			reverse_rotate(list_a, 1);
}

void	algorithm_five(t_ps_list **list_a, t_ps_list **list_b, int c)
{
	int	index;

	push(list_a, list_b, 1);
	index = (*list_b)->index;
	if (c == 5)
		push(list_a, list_b, 1);
	algorithm_three(list_a);
	if ((index > (*list_b)->index && (index != 5)) || (*list_b)->index == 5)
		swap(list_b, 2);
	while ((*list_a)->index + 1 != (*list_b)->index
		&& (*list_a)->index - 1 != (*list_b)->index)
		reverse_rotate(list_a, 1);
	if ((*list_a)->index > (*list_b)->index)
		push(list_a, list_b, 2);
	else
	{
		rotate(list_a, 1);
		push(list_a, list_b, 2);
	}
	if (c == 5)
		algorithm_five_pt2(list_a, list_b);
	algorithm_finish(list_a, c);
}

void	algorithm(t_ps_list **list_a, t_ps_list **list_b)
{
	int			size;

	if ((ft_lstsize((*list_a))) == 2)
		swap(list_a, 1);
	else if ((ft_lstsize((*list_a))) == 3)
		algorithm_three(list_a);
	else if ((ft_lstsize((*list_a))) == 4 || (ft_lstsize((*list_a))) == 5)
	{
		size = ft_lstsize(*list_a);
		algorithm_five(list_a, list_b, size);
	}
	else
		algorithm_rest(list_a, list_b);
}
