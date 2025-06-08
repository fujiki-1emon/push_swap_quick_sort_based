/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:05:17 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:05:18 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*curr;

	cnt = 0;
	curr = lst;
	while (curr)
	{
		cnt++;
		curr = curr->next;
	}
	return (cnt);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list *lst = NULL;
// 	t_list *elem1 = ft_lstnew("elem1");
// 	t_list *elem2 = ft_lstnew("elem2");
// 	t_list *elem3 = ft_lstnew("elem3");

// 	printf("lstsize = %d\n", ft_lstsize(lst));
// 	ft_lstadd_front(&lst, elem3);
// 	printf("lstsize = %d\n", ft_lstsize(lst));
// 	ft_lstadd_front(&lst, elem2);
// 	printf("lstsize = %d\n", ft_lstsize(lst));
// 	ft_lstadd_front(&lst, elem1);
// 	printf("lstsize = %d\n", ft_lstsize(lst));
// 	return (0);
// }
