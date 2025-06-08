/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:08:40 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:08:42 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	h = (char *)haystack;
	i = 0;
	while (h[i] && i < len)
	{
		j = 0;
		while (h[i + j] && needle[j] && j < len - i)
		{
			if (h[i + j] != needle[j])
				break ;
			j++;
		}
		if (needle[j] == '\0')
			return (&h[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("(0)  %s\n", ft_strnstr("Hello, world!", "Hell", 13));
// 	printf("(1)  %s\n", ft_strnstr("Hello, world!", "wor", 13));
// 	printf("(2)  %s\n", ft_strnstr("Hello, world!", "wor", 3));
// 	printf("(3)  %s\n", ft_strnstr("Hello, world!", "Hello, world!", 13));
// 	printf("(4)  %s\n", ft_strnstr("Hello, world!", "Hello, world!!", 100));
// 	printf("(5)  %s\n", ft_strnstr("Hello, world!", "Hel", 3));
// 	printf("(5)  %s\n", ft_strnstr("Hello, world!", "Hel", 2));
// 	return (0);
// }
