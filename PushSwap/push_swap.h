/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:08:53 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/01 07:57:59 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int			count_words(char *s);
int			char_error(int argc, char **argv);
int			repeat_error(t_ps_list *list);
void		free_all(t_ps_list *list);
void		create_list(char **s_vals, int c_words, t_ps_list **list, int c);
t_ps_list	*init_list(int argc, char **argv, t_ps_list **list);
long		ft_atol(const char *str);
int			int_error(int argc, char **argv, int c);
void		reverse_rotate(t_ps_list **list, int c);
void		rotate(t_ps_list **list, int c);
void		swap(t_ps_list **list, int c);
void		push(t_ps_list **list, t_ps_list **list_b, int c);
void		push_list_a(t_ps_list *list_a, t_ps_list **list_b);
void		push_list_b(t_ps_list **list_b, t_ps_list **list_a);
void		algorithm(t_ps_list **list_a, t_ps_list **list_b);
void		algorithm_three(t_ps_list **list_a);
void		algorithm_five(t_ps_list **list_a, t_ps_list **list_b, int c);
void		algorithm_five_pt2(t_ps_list **list_a, t_ps_list **list_b);
void		algorithm_finish(t_ps_list **list_a, int c);
void		algorithm_rest(t_ps_list **list_a, t_ps_list **list_b);
void		algorithm_rest_pt2(t_ps_list **list_a, t_ps_list **list_b);
int			check_sorted(t_ps_list **list_a);
void		create_index(t_ps_list **list);
int			*bubble_sort(int *values, int max);
void		swap_spec(t_ps_list **list, int c);
int			bit_size(int size);
void		error(void);

#endif
