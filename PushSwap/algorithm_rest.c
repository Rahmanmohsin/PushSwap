/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_rest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:16:16 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/03 14:18:40 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_rest_pt2(t_ps_list **list_a, t_ps_list **list_b)
{
	while ((*list_b))
	{
		push(&*list_a, &*list_b, 2);
		if (!(*list_b))
			break ;
	}
}

void	algorithm_rest(t_ps_list **list_a, t_ps_list **list_b)
{
	int			b_size;
	int			a_size;
	int			size;
	int			i;

	i = -1;
	b_size = bit_size(ft_lstsize(*list_a));
	a_size = ft_lstsize(*list_a);
	while (++i < b_size)
	{
		size = a_size;
		while (--size > -1)
		{
			if ((((*list_a)->index >> i) & 1) == 1)
				rotate(list_a, 1);
			else if ((((*list_a)->index >> i) & 1) == 0)
				push(list_a, list_b, 1);
		}
		algorithm_rest_pt2(list_a, list_b);
		if (check_sorted(list_a))
			break ;
		i++;
	}
}
