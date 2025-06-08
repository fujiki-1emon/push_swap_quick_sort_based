/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:16:42 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/17 22:13:51 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_context(t_sort_context **context, int arrsize, int array[],
		int rank_array[])
{
	int	i;

	*context = (t_sort_context *)malloc(sizeof(t_sort_context));
	if (!*context)
		return (EXIT_FAILURE);
	(*context)->arrsize = (size_t)arrsize;
	i = -1;
	while (++i < arrsize)
	{
		(*context)->array[i] = array[i];
		(*context)->rank_array[i] = rank_array[i];
	}
	i = -1;
	while (++i < arrsize)
		(*context)->rank_to_val[rank_array[i]] = array[i];
	(*context)->high = arrsize - 1;
	(*context)->low = 0;
	(*context)->range = -1;
	(*context)->pivot = -1;
	(*context)->nop = 0;
	(*context)->prev_op = -1;
	i = -1;
	while (++i < MAX_N_OP)
		(*context)->op_history[i] = -1;
	(*context)->n_recurse = 0;
	return (EXIT_SUCCESS);
}

int	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (EXIT_SUCCESS);
}

int	dedup_sorted_array(int sorted_array[], int arrsize, int *dedup_array[])
{
	int	ndup;
	int	i;
	int	j;
	int	k;

	ndup = 0;
	i = 0;
	j = -1;
	while (++j < arrsize)
		if (i < j && sorted_array[i++] == sorted_array[j])
			ndup++;
	*dedup_array = (int *)malloc(sizeof(int) * (arrsize - ndup));
	if (!dedup_array)
		return (-1);
	i = 0;
	j = -1;
	k = 0;
	while (++j < arrsize)
	{
		if (i < j && sorted_array[i++] == sorted_array[j])
			continue ;
		(*dedup_array)[k++] = sorted_array[j];
	}
	return (k);
}

int	array_value_to_index(int val, int arr[], int arrsize)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = arrsize - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (val == arr[mid])
		{
			return (mid);
		}
		else if (val < arr[mid])
			high = mid;
		else
			low = mid + 1;
	}
	return (INT_MIN);
}

int	*to_rank_array(int *array, int arrsize)
{
	int	*org_array;
	int	*rank_array;
	int	*dedup_array;
	int	dedup_arrsize;
	int	i;

	org_array = (int *)malloc(sizeof(int) * arrsize);
	if (!org_array)
		return (NULL);
	i = -1;
	while (++i < arrsize)
		org_array[i] = array[i];
	quick_sort_array(array, 0, arrsize);
	dedup_arrsize = dedup_sorted_array(array, arrsize, &dedup_array);
	if (dedup_arrsize == -1)
		return (NULL);
	rank_array = (int *)malloc(sizeof(int) * (arrsize));
	if (!rank_array)
		return (NULL);
	i = -1;
	while (++i < arrsize)
		rank_array[i] = array_value_to_index(org_array[i], dedup_array,
				dedup_arrsize);
	return (rank_array);
}
