/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:05:25 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/20 10:41:20 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*byte_str;
	size_t			i;

	chr = (unsigned char)c;
	byte_str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (byte_str[i] == chr)
		{
			return ((void *)((unsigned char *)s + i));
		}
		i++;
	}
	return (NULL);
}
