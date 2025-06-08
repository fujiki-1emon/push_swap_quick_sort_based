/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:04:37 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:04:38 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	if (lst)
		free(lst);
}

// #include <stdio.h>
// void print_lst(t_list *lst)
// {
// 	t_list *curr;
// 	int i = 0;
// 	curr = lst;
// 	while (curr)
// 	{
// 		printf(" [%d]: %s\n", i, (char *)curr->content);
// 		curr = curr->next;
// 		i++;
// 	}
// }
// void free_node_content(void *content)
// {
// 	if (content)
// 		free(content);
// }

// int main(void)
// {
// 	t_list *lst = NULL;
// 	t_list *elem1 = ft_lstnew(ft_strdup("elem1"));
// 	t_list *elem2 = ft_lstnew(ft_strdup("elem2"));
// 	t_list *elem3 = ft_lstnew(ft_strdup("elem3"));
// 	ft_lstadd_back(&lst, elem1);
// 	ft_lstadd_back(&lst, elem2);
// 	ft_lstadd_back(&lst, elem3);
// 	printf("lst\n");
// 	print_lst(lst);
// 	printf("### BEFORE ft_lstdelone ####\n");
// 	printf("elem2->content = %s\n", (char *)elem2->content);
// 	elem1->next = elem3;
// 	ft_lstdelone(elem2, &free_node_content);
// 	elem2 = NULL;
// 	if (!elem2)
// 		printf("### AFTER  ft_lstdelone ####\nelem2 = NULL\n");
// 	printf("lst\n");
// 	print_lst(lst);
// 	return (0);
// }
