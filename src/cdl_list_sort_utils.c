/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_list_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:18:32 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/17 16:16:58 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_cdl_list *list, bool (*cmp)(int, int))
{
	t_cdl_node	*curr;

	curr = list->head;
	while (curr != list->tail)
	{
		if (!(*cmp)(curr->data, curr->next->data))
			return (false);
		curr = curr->next;
	}
	return (true);
}

bool	is_ascending(int n1, int n2)
{
	return (n1 <= n2);
}

bool	is_descending(int n1, int n2)
{
	return (n2 <= n1);
}
