/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:51:24 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/18 00:30:38 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_operation(t_sort_context *context)
{
	int	i;

	i = -1;
	while (++i < context->nop)
	{
		printf("%s\n", (char *)get_op_name(context->op_history[i]));
	}
	return (EXIT_SUCCESS);
}

int	push_swap(int array[], int arrsize)
{
	t_cdl_list		stack_a;
	t_cdl_list		stack_b;
	t_sort_context	*context;
	int				*orig_array;

	orig_array = array;
	array = to_rank_array(orig_array, arrsize);
	if (init_context(&context, arrsize, orig_array, array) != 0)
		exit(1);
	if (build_stacks(array, arrsize, &stack_a, &stack_b) != 0)
		exit(1);
	if (stack_a.size == 1 || is_sorted(&stack_a, &is_ascending))
		return (EXIT_FAILURE);
	if (stack_a.size <= BASECASE_ARRSIZE)
	{
		if (rule_based_sort(&stack_a, &stack_b, context) != 0)
			return (EXIT_FAILURE);
	}
	else
		quick_sort_list(&stack_a, &stack_b, context);
	print_operation(context);
	return (EXIT_SUCCESS);
}
