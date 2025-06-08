/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:08:56 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 16:56:34 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_isin_charset(char c, const char *charset)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(charset);
	i = 0;
	while (i < len)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*get_empty_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static int	init_trimmed_str(char **trimmed, size_t start, size_t end)
{
	*trimmed = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!*trimmed)
		return (-1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && char_isin_charset(s1[start], set))
		start++;
	while (start < end && char_isin_charset(s1[end - 1], set))
		end--;
	if (end <= start)
		return (get_empty_str());
	if (init_trimmed_str(&trimmed, start, end) < 0)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

// #include <stdio.h>
// int main(void)
// {
// 	char test_0[] = "..,,.,|He||o,|wor!d!!!";
// 	char test_0_set[] = ",.|!";
// 	printf("(0) %s\n", ft_strtrim(test_0, test_0_set));

// 	char test_1[] = "aaaaaaaaaa";
// 	char test_1_set[] = "a";
// 	printf("(1) %s\n", ft_strtrim(test_1, test_1_set));
// 	return (0);
// }
