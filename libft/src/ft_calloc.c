/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:00:38 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:00:42 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ret;
	size_t			total;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size > 0 && (count > SIZE_MAX / size))
		return (NULL);
	total = count * size;
	ret = malloc(total);
	if (!ret)
		return (NULL);
	ft_bzero(ret, total);
	return ((void *)ret);
}
