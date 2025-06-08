/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:03:10 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/17 22:11:08 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "cdl_list.h"
# include "push_swap.h"

# define MAX_ARRSIZE 10000
# define MAX_N_OP 10000
# define BASECASE_ARRSIZE 6

# ifndef CDL_H
#  define CDL_H

typedef struct s_cdl_node
{
	int					data;
	struct s_cdl_node	*prev;
	struct s_cdl_node	*next;
}						t_cdl_node;

typedef struct s_cdl_list
{
	size_t				size;
	t_cdl_node			*head;
	t_cdl_node			*tail;
}						t_cdl_list;
# endif

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
}						t_operation;
# endif

typedef struct s_sort_context
{
	int					arrsize;
	int					array[MAX_ARRSIZE];
	int					rank_array[MAX_ARRSIZE];
	int					rank_to_val[MAX_ARRSIZE];
	int					high;
	int					low;
	int					range;
	int					pivot;
	int					nop;
	t_operation			prev_op;
	t_operation			op_history[MAX_N_OP];
	int					n_recurse;

}						t_sort_context;

int						print_array(int arr[], int arrsize);
int						quick_sort_array(int array[], int left, int right);
int						quick_sort_list(t_cdl_list *stack_a,
							t_cdl_list *stack_b, t_sort_context *context);
int						rule_based_sort(t_cdl_list *stack_a,
							t_cdl_list *stack_b, t_sort_context *context);
int						sort_n_6(t_cdl_list *stack_a, t_cdl_list *stack_b,
							t_sort_context *context);
int						sort_n_6_b(t_cdl_list *stack_a, t_cdl_list *stack_b,
							t_sort_context *context, int low);
/* sort_helper */
int						init_context(t_sort_context **context, int arrsize,
							int array[], int rank_array[]);
int						ft_swap(int *a, int *b);
int						*to_rank_array(int *array, int arrsize);

#endif
