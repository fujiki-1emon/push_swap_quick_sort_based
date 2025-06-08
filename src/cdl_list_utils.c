/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:10:49 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/18 23:07:36 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_list(t_cdl_list *list)
{
	size_t		idx;
	t_cdl_node	*curr;
	t_cdl_node	*tail;

	curr = list->head;
	tail = list->tail;
	idx = 0;
	printf("list.size = %d\n", (int)list->size);
	while (curr)
	{
		printf("list[%zu] = %d\n", idx, curr->data);
		if (curr == tail)
			return (EXIT_SUCCESS);
		curr = curr->next;
		idx++;
	}
	return (EXIT_FAILURE);
}

int	list_to_array(t_cdl_list *list, int array[])
{
	int			arrsize;
	int			i;
	t_cdl_node	*node;

	arrsize = 0;
	node = list->head;
	while (1)
	{
		arrsize++;
		if (node == list->tail)
			break ;
		node = node->next;
	}
	array = (int *)malloc(sizeof(int) * arrsize);
	if (!array)
		return (-1);
	i = -1;
	node = list->head;
	while (++i < arrsize)
	{
		array[i] = node->data;
		node = node->next;
	}
	return (arrsize);
}
