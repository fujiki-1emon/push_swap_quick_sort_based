/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:04:30 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:04:31 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	if (!lst || !del)
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		del(curr->content);
		free(curr);
		curr = next;
	}
	*lst = NULL;
}

// #include <stdio.h>
// void	print_lst(t_list *lst)
// {
// 	t_list	*curr;
// 	int		i;

// 	if (!lst)
// 		printf("lst has no elements.\n");
// 	i = 0;
// 	curr = lst;
// 	while (curr)
// 	{
// 		printf(" [%d]: %s\n", i, (char *)curr->content);
// 		curr = curr->next;
// 		i++;
// 	}
// }
// void	free_node_content(void *content)
// {
// 	if (content)
// 		free(content);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*elem1;
// 	t_list	*elem2;
// 	t_list	*elem3;

// 	lst = NULL;
// 	elem1 = ft_lstnew(ft_strdup("elem1"));
// 	elem2 = ft_lstnew(ft_strdup("elem2"));
// 	elem3 = ft_lstnew(ft_strdup("elem3"));
// 	ft_lstadd_back(&lst, elem1);
// 	ft_lstadd_back(&lst, elem2);
// 	ft_lstadd_back(&lst, elem3);
// 	printf("### BEFORE ft_lstclear ####\n");
// 	printf("lst\n");
// 	print_lst(lst);
// 	printf("\n");
// 	ft_lstclear(&lst, &free_node_content);
// 	printf("### AFTER  ft_lstclear ####\n");
// 	printf("lst\n");
// 	print_lst(lst);
// 	return (0);
// }
