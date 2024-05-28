/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:02:58 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/02 23:00:21 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_index(t_ps_list **list)
{
	t_ps_list	*temp;
	int			*values;
	int			i;

	values = malloc(ft_lstsize((*list)) * sizeof(int));
	if (!values)
		return (free_all((*list)), write(1, "Error\n", 6), error());
	temp = (*list);
	i = -1;
	while (temp != NULL && ++i < ft_lstsize((*list)))
	{
		values[i] = temp->value;
		temp = temp->next;
	}
	values = bubble_sort(values, i + 1);
	temp = (*list);
	while (temp != NULL)
	{
		i = -1;
		while (++i < ft_lstsize((*list)))
			if (temp->value == values[i])
				temp->index = i + 1;
		temp = temp->next;
	}
	free(values);
}

void	create_list(char **s_vals, int c_words, t_ps_list **list, int c)
{
	int			i;
	t_ps_list	*temp;
	t_ps_list	*next_node;

	i = c - 1;
	*list = malloc(sizeof(t_ps_list));
	if (!(*list))
		return (write(1, "Error\n", 6), error());
	temp = *list;
	while (i < c_words)
	{
		temp->value = ft_atoi(s_vals[i]);
		next_node = malloc(sizeof(t_ps_list));
		if (!next_node)
			return (free_all(temp), write(1, "Error\n", 6), error());
		temp->next = next_node;
		next_node->prev = temp;
		if (i + 1 != c_words)
			temp = temp->next;
		i++;
	}
	free(next_node);
	temp->next = NULL;
}

t_ps_list	*init_list(int argc, char **argv, t_ps_list **list)
{
	char	**s_vals;

	s_vals = NULL;
	if (argc == 2)
		s_vals = ft_split(argv[1], ' ');
	if (s_vals != NULL)
		if (!int_error(count_words(argv[1]), s_vals, 1))
			return (NULL);
	if (!int_error(argc, argv, 2))
		return (NULL);
	if (s_vals != NULL)
		create_list(s_vals, count_words(argv[1]), list, 1);
	else
		create_list(argv, argc, list, 2);
	create_index(list);
	return (*list);
}
