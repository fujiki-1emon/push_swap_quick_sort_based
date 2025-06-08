/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:07:17 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:07:24 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		src_len;
	int		i;

	src_len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		dest[i] = s1[i];
	}
	dest[i] = '\0';
	return (dest);
}
