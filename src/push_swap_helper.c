/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:51:24 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/17 16:40:21 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	build_stacks(int array[], int arrsize, t_cdl_list *a, t_cdl_list *b)
{
	t_cdl_node	*node;
	int			i;

	init_list(a);
	init_list(b);
	i = -1;
	while (++i < arrsize)
	{
		node = create_node(array[i]);
		if (push_back(a, node) != 0)
			exit(1);
	}
	return (EXIT_SUCCESS);
}

int	operate_on_stacks(t_cdl_list *stack_a, t_cdl_list *stack_b, t_operation op)
{
	t_cdl_node	*node;

	if (op == SA)
	{
		if (swap_top2(stack_a) != 0)
			exit(1);
	}
	else if (op == SB)
	{
		if (swap_top2(stack_b) != 0)
			exit(1);
	}
	else if (op == SS)
	{
		if (swap_top2(stack_a) != 0 || swap_top2(stack_b) != 0)
			exit(1);
	}
	else if (op == PA)
	{
		node = pop_front(stack_b);
		if (!node)
			exit(1);
		if (push_front(stack_a, node) != 0)
			exit(1);
	}
	else if (op == PB)
	{
		node = pop_front(stack_a);
		if (!node)
			exit(1);
		if (push_front(stack_b, node) != 0)
			exit(1);
	}
	else if (op == RA || op == RR)
	{
		if (rotate(stack_a) != 0)
			exit(1);
	}
	else if (op == RB || op == RR)
	{
		if (rotate(stack_b) != 0)
			exit(1);
	}
	else if (op == RRA || op == RRR)
	{
		if (reverse_rotate(stack_a) != 0)
			exit(1);
	}
	else if (op == RRB || op == RRR)
	{
		if (reverse_rotate(stack_b) != 0)
			exit(1);
	}
	else
		exit(1);
	return (EXIT_SUCCESS);
}

int	apply_operation(t_cdl_list *stack_a, t_cdl_list *stack_b,
		t_sort_context *context, t_operation op)
{
	operate_on_stacks(stack_a, stack_b, op);
	context->op_history[context->nop++] = op;
	return (EXIT_SUCCESS);
}

const char	*get_op_name(t_operation op)
{
	static const char	*op_names[11] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr",
	};

	if (op < 0 || RRR < op)
		return ("InvalidOP");
	return (op_names[op]);
}
