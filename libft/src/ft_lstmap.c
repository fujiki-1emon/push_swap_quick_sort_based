/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:04:59 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 18:32:52 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_elem(t_list *elem, void (*del)(void *))
{
	if (elem)
	{
		del(elem->content);
		free(elem);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*curr;
	t_list	*curr2;
	t_list	*elem;

	if (!lst)
		return (NULL);
	curr = lst;
	lst2 = ft_lstnew(f(curr->content));
	if (!lst2)
		return (NULL);
	curr2 = lst2;
	curr = curr->next;
	while (curr)
	{
		elem = ft_lstnew(f(curr->content));
		if (!elem)
			return (free_elem(elem, del), NULL);
		curr2->next = elem;
		curr = curr->next;
		curr2 = curr2->next;
	}
	return (lst2);
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

// void *my_toupper(void *content)
// {
// 	char *str;
// 	size_t len;
// 	int i;

// 	len = ft_strlen((char *)content);
// 	str = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (((char *)content)[i])
// 	{
// 		str[i] = ft_toupper(((char *)content)[i]);
// 		i++;
// 	}
// 	return (str);
// }

// void mock_del(void *content)
// {
// 	(void)content;
// 	return ;
// }

// int main(void)
// {
// 	t_list *lst = NULL;
// 	t_list *lst2 = NULL;
// 	t_list *elem1 = ft_lstnew(ft_strdup("elem1"));
// 	t_list *elem2 = ft_lstnew(ft_strdup("elem2"));
// 	t_list *elem3 = ft_lstnew(ft_strdup("elem3"));
// 	t_list *elem100 = ft_lstnew(ft_strdup("elem100dayo"));
// 	ft_lstadd_back(&lst, elem1);
// 	ft_lstadd_back(&lst, elem2);
// 	ft_lstadd_back(&lst, elem3);
// 	ft_lstadd_back(&lst, elem100);
// 	printf("--- BEFORE ft_lstmap ---\n");
// 	printf("lst\n");
// 	print_lst(lst);
// 	lst2 = ft_lstmap(lst, &my_toupper, &mock_del);
// 	printf("--- AFTER  ft_lstmap ---\n");
// 	printf("lst\n");
// 	print_lst(lst);
// 	printf("lst2\n");
// 	print_lst(lst2);
// 	return (0);
// }
