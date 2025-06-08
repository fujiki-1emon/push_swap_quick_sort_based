/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:04:44 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:04:45 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	if (!lst)
		return ;
	curr = lst;
	while (curr)
	{
		f(curr->content);
		curr = curr->next;
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
// 		printf(" [%d]: %s\n", i, (char *)curr->content);
// 		curr = curr->next;
// 		i++;
// 	}
// }

// void capitalize(void *content)
// {
// 	if ('a' <= *(char *)content && *(char *)content <= 'z')
// 		*(char *)content = *(char *)content - 'a' + 'A';
// }

// int main(void)
// {
// 	t_list *lst = NULL;
// 	t_list *elem1 = ft_lstnew(ft_strdup("elem1"));
// 	t_list *elem2 = ft_lstnew(ft_strdup("elem2"));
// 	t_list *elem3 = ft_lstnew(ft_strdup("elem3"));
// 	t_list *elem100 = ft_lstnew(ft_strdup("Hello, world!"));
// 	ft_lstadd_back(&lst, elem1);
// 	ft_lstadd_back(&lst, elem2);
// 	ft_lstadd_back(&lst, elem3);
// 	ft_lstadd_back(&lst, elem100);
// 	printf("--- BEFORE ft_lstiter ---\nlst\n");
// 	print_lst(lst);
// 	ft_lstiter(lst, &capitalize);
// 	printf("--- AFTER  ft_lstiter ---\nlst\n");
// 	print_lst(lst);
// 	return (0);
// }
