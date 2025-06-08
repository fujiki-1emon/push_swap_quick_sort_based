/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_list_io.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:18:32 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/17 23:32:50 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_front(t_cdl_list *list, t_cdl_node *node)
{
	if (!list || !node)
		return (EXIT_FAILURE);
	if (list->head)
	{
		list->head->prev = node;
		node->next = list->head;
		node->prev = list->tail;
		list->head = node;
		list->tail->next = node;
	}
	else
	{
		list->head = node;
		list->tail = node;
		node->next = node;
		node->prev = node;
	}
	list->size++;
	return (EXIT_SUCCESS);
}

int	push_back(t_cdl_list *list, t_cdl_node *node)
{
	if (!list || !node)
		return (EXIT_FAILURE);
	if (list->tail)
	{
		list->tail->next = node;
		node->prev = list->tail;
		node->next = list->head;
		list->tail = node;
		list->head->prev = node;
	}
	else
	{
		list->head = node;
		list->tail = node;
		node->next = node;
		node->prev = node;
	}
	list->size++;
	return (EXIT_SUCCESS);
}

t_cdl_node	*pop_front(t_cdl_list *list)
{
	t_cdl_node	*first;
	t_cdl_node	*second;

	if (list->size < 1 || !list || !list->head)
		return (NULL);
	first = list->head;
	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		second = first->next;
		list->head = second;
		second->prev = list->tail;
		list->tail->next = second;
	}
	first->next = NULL;
	first->prev = NULL;
	list->size--;
	return (first);
}

t_cdl_node	*pop_back(t_cdl_list *list)
{
	t_cdl_node	*last;
	t_cdl_node	*second_last;

	if (list->size < 1 || !list || !list->tail)
		return (NULL);
	last = list->tail;
	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		second_last = last->prev;
		list->tail = second_last;
		second_last->next = last->next;
		list->head->prev = second_last;
	}
	last->next = NULL;
	last->prev = NULL;
	list->size--;
	return (last);
}
