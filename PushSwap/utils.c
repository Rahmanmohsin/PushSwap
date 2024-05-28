/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:09:54 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/02 22:45:21 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s)
{
	int	i;
	int	spaces;

	spaces = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			spaces++;
		if (i > 0 && s[i] == ' ' && s[i - 1] == ' ')
			spaces--;
		i++;
	}
	return (spaces + 1);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	*bubble_sort(int *values, int max)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < max)
	{
		j = -1;
		while (++j < max)
		{
			if (values[j + 1] < values[j])
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
		}
	}
	return (values);
}

int	bit_size(int size)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		i++;
		size = size / 2;
	}
	return (i);
}
