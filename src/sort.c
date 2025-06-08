/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:16:42 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/20 10:51:37 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

int	quick_sort_array(int array[], int left, int right)
{
	int	pivot_ind;
	int	i;
	int	j;

	if (right - left <= 1)
		return (EXIT_SUCCESS);
	pivot_ind = (left + right) / 2;
	ft_swap(&array[pivot_ind], &array[right - 1]);
	i = left;
	j = i;
	while (j < right - 1)
	{
		if (array[j] < array[right - 1])
		{
			ft_swap(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	ft_swap(&array[i], &array[right - 1]);
	quick_sort_array(array, left, i);
	quick_sort_array(array, i + 1, right);
	return (EXIT_SUCCESS);
}

static int	quick_sort_list_b_basecase(t_cdl_list *stack_a, t_cdl_list *stack_b,
		t_sort_context *context, int low)
{
	sort_n_6_b(stack_a, stack_b, context, low);
	while (stack_b->size > 0)
	{
		apply_operation(stack_a, stack_b, context, PA);
		apply_operation(stack_a, stack_b, context, RA);
	}
	return (EXIT_SUCCESS);
}

int	quick_sort_list_b(t_cdl_list *stack_a, t_cdl_list *stack_b,
		t_sort_context *context, int low, int high)
{
	int	pivot;

	if (stack_b->size <= BASECASE_ARRSIZE)
		return (quick_sort_list_b_basecase(stack_a, stack_b, context, low));
	pivot = (low + high + 1) / 2;
	while (stack_b->size > (pivot - low + 1))
	{
		if (stack_b->head->data > pivot)
			apply_operation(stack_a, stack_b, context, PA);
		else
			apply_operation(stack_a, stack_b, context, RB);
	}
	quick_sort_list_b(stack_a, stack_b, context, low, pivot);
	while (stack_b->size < (high - pivot))
	{
		if ((pivot < stack_a->head->data) && (stack_a->head->data <= high))
			apply_operation(stack_a, stack_b, context, PB);
		else
			apply_operation(stack_a, stack_b, context, RA);
	}
	quick_sort_list_b(stack_a, stack_b, context, pivot + 1, high);
	return (EXIT_SUCCESS);
}

int	quick_sort_list(t_cdl_list *stack_a, t_cdl_list *stack_b,
		t_sort_context *ctx)
{
	ctx->pivot = (ctx->low + ctx->high + 1) / 2;
	while (stack_b->size < (ctx->pivot - ctx->low))
	{
		if ((ctx->low <= stack_a->head->data)
			&& (stack_a->head->data < ctx->pivot))
			apply_operation(stack_a, stack_b, ctx, PB);
		else
			apply_operation(stack_a, stack_b, ctx, RA);
	}
	quick_sort_list_b(stack_a, stack_b, ctx, ctx->low, ctx->pivot);
	if (stack_a->size == ctx->arrsize && is_sorted(stack_a, &is_ascending))
		return (EXIT_SUCCESS);
	while (stack_b->size < (ctx->high - ctx->pivot + 1))
	{
		if ((ctx->pivot <= stack_a->head->data)
			&& (stack_a->head->data < ctx->high + 1))
			apply_operation(stack_a, stack_b, ctx, PB);
		else
			apply_operation(stack_a, stack_b, ctx, RA);
	}
	if (stack_a->size <= BASECASE_ARRSIZE)
		sort_n_6(stack_a, stack_b, ctx);
	quick_sort_list_b(stack_a, stack_b, ctx, ctx->pivot, ctx->high);
	return (EXIT_SUCCESS);
}
