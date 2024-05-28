/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:26:56 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/01 07:30:19 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_ps_list *list)
{
	t_ps_list	*current;
	t_ps_list	*next;

	current = list;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

// void	free_split(char	**split, int i)
// {
// 	while (i > -1)
// 	{
// 		free(split[i]);
// 		i--;
// 	}
// 	free(split);
// }
