/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:09:05 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 17:29:42 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_empty_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	start_i;
	size_t	str_len;
	size_t	substr_len;
	size_t	i;

	start_i = (size_t)start;
	str_len = ft_strlen(s);
	substr_len = str_len - start_i;
	if (len == 0 || start_i >= str_len)
		return (get_empty_str());
	if (len >= substr_len)
		len = substr_len;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	test_0[] = "Hello, world!";

// 	printf("(0) %s\n", ft_substr(test_0, 7, 5));
// 	printf("(1) %s\n", ft_substr(test_0, 20, 5));
// 	printf("(2) %s\n", ft_substr(test_0, 7, 100));
// 	printf("(3) %s\n", ft_substr(test_0, 7, 0));
// 	return (0);
// }
