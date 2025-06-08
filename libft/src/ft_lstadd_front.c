/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:04:21 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:04:23 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*head;

	head = *lst;
	if (head)
	{
		*lst = new;
		new->next = head;
	}
	else
	{
		*lst = new;
	}
}

// #include <stdio.h>
// void print_lst(t_list *lst)
// {
// 	t_list *curr;
// 	int i = 0;
// 	curr = lst;
// 	while (curr)
// 	{
// 		printf("lst[%d]: %s\n", i, (char *)curr->content);
// 		curr = curr->next;
// 		i++;
// 	}
// }

// int main(void)
// {
// 	t_list *lst = NULL;
// 	t_list *elem1 = ft_lstnew("elem1");
// 	t_list *elem2 = ft_lstnew("elem2");
// 	t_list *elem3 = ft_lstnew("elem3");
// 	ft_lstadd_front(&lst, elem3);
// 	ft_lstadd_front(&lst, elem2);
// 	ft_lstadd_front(&lst, elem1);
// 	print_lst(lst);
// 	return (0);
// }
