/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:07:00 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:07:02 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *str, size_t n)
{
	char	*duplicated;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	duplicated = (char *)malloc(sizeof(char) * (len + 1));
	if (!duplicated)
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		duplicated[i] = str[i];
		i++;
	}
	duplicated[i] = '\0';
	return (duplicated);
}

static int	count_words(const char *str, const char delim)
{
	int		cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (!(str[i++] == delim) && ((str[i] == delim) || str[i] == '\0'))
			cnt++;
	}
	return (cnt);
}

static int	init_splits(const char *str, const char delim, char ***splits)
{
	int	words;

	words = count_words(str, delim);
	*splits = (char **)malloc(sizeof(char *) * (words + 1));
	if (!*splits)
		return (-1);
	return (0);
}

static void	maybe_free_splits(char **splits, int words)
{
	if (!splits[words - 1])
	{
		while (--words >= 0)
			free(splits[words]);
		free(splits);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**splits;
	int		words;
	size_t	i;
	size_t	start_i;

	if (init_splits(s, c, &splits) < 0)
		return (NULL);
	words = 0;
	i = 0;
	start_i = i;
	while (s[i])
	{
		if ((s[i] == c))
		{
			i++;
			start_i = i;
		}
		else if (!(s[i++] == c) && ((s[i] == c) || s[i] == '\0'))
		{
			splits[words++] = ft_strndup(&s[start_i], i - start_i);
			maybe_free_splits(splits, words);
		}
	}
	splits[words] = NULL;
	return (splits);
}

// #include <stdio.h>
// int main(void)
// {
// 	size_t i;

// 	char *test_0 = "Hello, world!";
// 	char test_0_c = ' ';
// 	char **test_0_ret;
// 	test_0_ret = ft_split(test_0, test_0_c);
// 	printf("(0)  '%s'\n", test_0);
// 	i = 0;
// 	while (test_0_ret[i])
// 	{
// 		printf(" %d: %s\n", (int)i, test_0_ret[i]);
// 		i++;
// 	}

// 	char *test_1 = "|||Hello|, ||||world|!|||";
// 	char test_1_c = '|';
// 	char **test_1_ret;
// 	test_1_ret = ft_split(test_1, test_1_c);
// 	printf("(1)  '%s'\n", test_1);
// 	i = 0;
// 	while (test_1_ret[i])
// 	{
// 		printf(" %d: %s\n", (int)i, test_1_ret[i]);
// 		i++;
// 	}

// 	char *test_2 = "||Hello|, |||||world|!||||";
// 	char test_2_c = '|';
// 	char **test_2_ret;
// 	test_2_ret = ft_split(test_2, test_2_c);
// 	printf("(1)  '%s'\n", test_2);
// 	i = 0;
// 	while (test_2_ret[i])
// 	{
// 		printf(" %d: %s\n", (int)i, test_2_ret[i]);
// 		i++;
// 	}

// 	return (0);
// }
/* Test ft_strndup() */
// int main(void)
// {
// 	printf("%s\n", ft_strndup("Hello, world!", 20));
// 	printf("%s\n", ft_strndup("Hello, world!", 2));
// 	return (0);
// }
/* Test count_words() */
// int main(void)
// {
// 	char const test_0[] = " He lo, world! ";
// 	char test_0_c = ' ';
// 	printf("%d\n", count_words(test_0, test_0_c));
// 	return (0);
// }
