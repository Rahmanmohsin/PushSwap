/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:00:00 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/03 15:09:46 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//leaks at ./push_swap 1
//should parse ./push_swap 3 2 "1 0" and work
// ./push_swap  0 1 3 434234234234324324234324 32 //finish
// ./push_swap "" return error

int	main(int argc, char **argv)
{
	t_ps_list	*list;
	t_ps_list	*list_b;

	list = NULL;
	list_b = NULL;
	if (argc < 2 || !(*argv[1]) || !argv[1])
		return (0);
	if (!char_error(argc, argv))
		return (write(1, "Error\n", 6), 1);
	list = init_list(argc, argv, &list);
	if (!list)
		return (write(1, "Error", 6), 1);
	if (!repeat_error(list))
		return (free_all(list), list = NULL, write(1, "Error\n", 6), 1);
	if (check_sorted(&list))
		return (free_all(list), list = NULL, 1);
	algorithm(&list, &list_b);
	free_all(list);
	free_all(list_b);
	return (0);
}
