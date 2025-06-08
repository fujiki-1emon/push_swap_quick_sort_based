/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:07:39 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 18:24:54 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len > SIZE_MAX - s2_len)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, s1_len + 1);
	ft_strlcpy(&s3[s1_len], s2, s2_len + 1);
	return (s3);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("(0) %s\n", ft_strjoin("Hello, ", "world!"));
// 	return (0);
// }
