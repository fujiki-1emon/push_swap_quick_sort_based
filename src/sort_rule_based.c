/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rule_based.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:16:42 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/20 10:54:06 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

int	sort_n_3(t_cdl_list *stack_a, t_cdl_list *stack_b, t_sort_context *context)
{
	t_cdl_node	*first;
	t_cdl_node	*second;
	t_cdl_node	*third;

	first = stack_a->head;
	second = first->next;
	third = second->next;
	if (first->data < third->data && third->data < second->data)
	{
		apply_operation(stack_a, stack_b, context, RRA);
		apply_operation(stack_a, stack_b, context, SA);
	}
	else if (second->data < first->data && first->data < third->data)
		apply_operation(stack_a, stack_b, context, SA);
	else if (third->data < first->data && first->data < second->data)
		apply_operation(stack_a, stack_b, context, RRA);
	else if (second->data < third->data && third->data < first->data)
		apply_operation(stack_a, stack_b, context, RA);
	else if (third->data < second->data && second->data < first->data)
	{
		apply_operation(stack_a, stack_b, context, SA);
		apply_operation(stack_a, stack_b, context, RRA);
	}
	return (EXIT_SUCCESS);
}

int	sort_n_3_b(t_cdl_list *stack_a, t_cdl_list *stack_b,
		t_sort_context *context)
{
	t_cdl_node	*first;
	t_cdl_node	*second;
	t_cdl_node	*third;

	first = stack_b->head;
	second = first->next;
	third = second->next;
	if (first->data < third->data && third->data < second->data)
	{
		apply_operation(stack_a, stack_b, context, RRB);
		apply_operation(stack_a, stack_b, context, SB);
	}
	else if (second->data < first->data && first->data < third->data)
		apply_operation(stack_a, stack_b, context, SB);
	else if (third->data < first->data && first->data < second->data)
		apply_operation(stack_a, stack_b, context, RRB);
	else if (second->data < third->data && third->data < first->data)
		apply_operation(stack_a, stack_b, context, RB);
	else if (third->data < second->data && second->data < first->data)
	{
		apply_operation(stack_a, stack_b, context, RB);
		apply_operation(stack_a, stack_b, context, SB);
	}
	return (EXIT_SUCCESS);
}

int	sort_n_6(t_cdl_list *stack_a, t_cdl_list *stack_b, t_sort_context *context)
{
	t_cdl_node	*node;
	int			pivot;
	int			i;

	pivot = stack_a->size - 3 - 1;
	i = 0;
	while (i <= pivot)
	{
		node = stack_a->head;
		if (node->data <= pivot)
			(apply_operation(stack_a, stack_b, context, PB), i++);
		else
			apply_operation(stack_a, stack_b, context, RA);
	}
	sort_n_3(stack_a, stack_b, context);
	while (stack_b->size > 0 && pivot >= 0)
	{
		node = stack_b->head;
		if (node->data == pivot)
			(apply_operation(stack_a, stack_b, context, PA), --pivot);
		else
			apply_operation(stack_a, stack_b, context, RB);
	}
	return (EXIT_SUCCESS);
}

int	sort_n_6_b(t_cdl_list *stack_a, t_cdl_list *stack_b,
		t_sort_context *context, int low)
{
	t_cdl_node	*node;
	int			low_orig;

	if (is_sorted(stack_b, &is_ascending) == 1)
		return (EXIT_SUCCESS);
	low_orig = low;
	while (stack_b->size > 3)
	{
		node = stack_b->head;
		if (node->data == low)
			(apply_operation(stack_a, stack_b, context, PA), low++);
		else
			apply_operation(stack_a, stack_b, context, RB);
	}
	sort_n_3_b(stack_a, stack_b, context);
	while (low_orig <= --low)
	{
		node = stack_a->head;
		if (node->data == low)
			apply_operation(stack_a, stack_b, context, PB);
		else
			apply_operation(stack_a, stack_b, context, RA);
	}
	return (EXIT_SUCCESS);
}

int	rule_based_sort(t_cdl_list *stack_a, t_cdl_list *stack_b,
		t_sort_context *context)
{
	t_cdl_node	*first;
	t_cdl_node	*second;

	if (stack_a->size == 2)
	{
		(void)stack_b;
		first = stack_a->head;
		second = first->next;
		if (second->data < first->data)
			context->op_history[context->nop++] = SA;
	}
	else if (stack_a->size == 3)
	{
		if (sort_n_3(stack_a, stack_b, context) != 0)
			exit(1);
	}
	else if (stack_a->size <= 6)
	{
		if (sort_n_6(stack_a, stack_b, context) != 0)
			exit(1);
	}
	return (EXIT_SUCCESS);
}
