/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:18:32 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/18 00:32:39 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(t_cdl_list *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

t_cdl_node	*create_node(int data)
{
	t_cdl_node	*new_node;

	new_node = (t_cdl_node *)malloc(sizeof(t_cdl_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

int	rotate(t_cdl_list *list)
{
	t_cdl_node	*first;

	if (list->size <= 1 || !list)
		exit(1);
	first = pop_front(list);
	push_back(list, first);
	return (EXIT_SUCCESS);
}

int	reverse_rotate(t_cdl_list *list)
{
	t_cdl_node	*last;

	if (list->size <= 1 || !list)
		return (EXIT_FAILURE);
	last = pop_back(list);
	push_front(list, last);
	return (EXIT_SUCCESS);
}

int	swap_top2(t_cdl_list *list)
{
	t_cdl_node	*first;
	t_cdl_node	*second;

	if (list->size < 2)
		return (EXIT_FAILURE);
	if (list->size == 2)
	{
		first = list->head;
		second = first->next;
		list->head = second;
		list->tail = first;
		return (EXIT_SUCCESS);
	}
	first = list->head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = list->tail;
	second->next = first;
	list->head = second;
	list->tail->next = second;
	return (EXIT_SUCCESS);
}
