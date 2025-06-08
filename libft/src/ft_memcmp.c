/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:05:32 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:05:33 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*bs1;
	unsigned char	*bs2;
	size_t			i;

	if (n == 0)
		return (0);
	bs1 = (unsigned char *)s1;
	bs2 = (unsigned char *)s2;
	i = 0;
	while (bs1[i] == bs2[i])
	{
		if (i == n - 1)
			return (0);
		i++;
	}
	return (bs1[i] - bs2[i]);
}
