/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:04:56 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/07 16:51:21 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//% ./push_swap "3 2" 1 list should be 3 2 1
//check leaks

int	char_error(int argc, char **argv)
{
	int	i;
	int	minus;

	minus = 0;
	while (argc > 1)
	{
		i = -1;
		while (argv[argc - 1][++i] != '\0')
		{
			if (argv[argc - 1][i] >= '0' && argv[argc - 1][i] <= '9')
				minus = 0;
			if (argv[argc - 1][i] == '-')
				minus++;
			if ((argv[argc - 1][i] == '-' && !(argv[argc - 1][i + 1] >= '0'
				&& argv[argc - 1][i + 1] <= '9')) || (argv[argc - 1][i] == '-'
				&& i > 0 && argv[argc - 1][i - 1] != ' '))
				return (0);
			if (((argv[argc - 1][i] < '0' || argv[argc - 1][i] > '9')
				&& (argv[argc - 1][i] != ' ' && argv[argc - 1][i] != '-'))
				|| minus > 1)
				return (0);
		}
		argc--;
	}
	return (1);
}

int	repeat_error(t_ps_list *list)
{
	t_ps_list	*temp;
	t_ps_list	*test_vals;

	temp = list;
	while (temp->next != NULL)
	{
		test_vals = temp->next;
		while (test_vals != NULL)
		{
			if (temp->value == test_vals->value)
				return (0);
			test_vals = test_vals->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	int_error(int argc, char **argv, int c)
{
	int		i;
	long	check;

	check = 0;
	i = c - 1;
	while (i < argc)
	{
		check = ft_atol(argv[i]);
		if (check > 2147483647 || check < -2147483648)
			return (write(1, "Error\n", 6), error(), 0);
		if (check == 0 && argv[argc - 1][0] != '0')
			return (write(1, "Error\n", 6), error(), 0);
		i++;
	}
	return (1);
}

int	check_sorted(t_ps_list **list_a)
{
	t_ps_list	*list;
	t_ps_list	*check;

	list = (*list_a);
	while (list->next != NULL)
	{
		check = list->next;
		while (check != NULL)
		{
			if (check->value < list->value)
				return (0);
			check = check->next;
		}
		list = list->next;
	}
	return (1);
}

void	error(void)
{
	exit(1);
}
