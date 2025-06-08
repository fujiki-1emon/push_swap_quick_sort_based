/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:08:48 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:08:50 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	int		len;

	chr = (char)c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == chr)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
