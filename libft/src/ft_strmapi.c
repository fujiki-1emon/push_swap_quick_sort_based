/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:08:16 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:08:18 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	mapped = (char *)malloc(sizeof(char) * (len + 1));
	if (!mapped)
		return (NULL);
	while (i < len)
	{
		mapped[i] = f((unsigned int)i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}

// char my_toupper(unsigned int idx, char c)
// {
// 	(void)idx;
// 	if ('a' <= c && c <= 'z')
// 		return (c - 'a' + 'A');
// 	return (c);
// }

// #include <stdio.h>
// int main(void)
// {
// 	char test_0[] = "Hello, world!";
// 	printf("(0)\n");
// 	printf("ft_strmapi(%s) = %s\n", test_0, ft_strmapi(test_0, &my_toupper));
// 	return (0);
// }
