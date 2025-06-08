/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:04:52 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:04:53 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*elem1;
// 	t_list	*elem2;
// 	t_list	*elem3;
// 	t_list	*last_elem;

// 	lst = NULL;
// 	elem1 = ft_lstnew("elem1");
// 	elem2 = ft_lstnew("elem2");
// 	elem3 = ft_lstnew("elem3");
// 	ft_lstadd_front(&lst, elem3);
// 	ft_lstadd_front(&lst, elem2);
// 	ft_lstadd_front(&lst, elem1);
// 	last_elem = ft_lstlast(lst);
// 	printf("last_elem->content = %s\n", (char *)last_elem->content);
// 	return (0);
// }
