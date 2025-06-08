/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:07:10 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:07:12 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	int		len;
	int		i;

	chr = (char)c;
	i = -1;
	len = ft_strlen(s);
	while (++i <= len)
		if (s[i] == chr)
			return ((char *)&s[i]);
	return (NULL);
}
