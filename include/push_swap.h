/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:37:20 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/15 23:07:28 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "cdl_list.h"
# include "libft.h"
# include "sort.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef T_OPERATION
#  define T_OPERATION

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}			t_operation;

# endif

/* push_swap */
int			push_swap(int array[], int arrsize);
/* push_swap_helper */
int			build_stacks(int array[], int arrsize, t_cdl_list *a,
				t_cdl_list *b);
int			operate_on_stacks(t_cdl_list *stack_a, t_cdl_list *stack_b,
				t_operation op);
int			apply_operation(t_cdl_list *stack_a, t_cdl_list *stack_b,
				t_sort_context *context, t_operation op);
const char	*get_op_name(t_operation op);
/* libft_plus */
int			ft_isspace(char c);
/* argparse */
int			is_num_str(char *str);
int			parse_int_array(char *str, int *array[]);

#endif
