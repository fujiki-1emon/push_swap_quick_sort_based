/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:08:26 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/16 15:09:52 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num_str(char *str)
{
	size_t	i;
	size_t	len;
	int		nspace;

	nspace = 0;
	i = 0;
	len = ft_strlen((const char *)str);
	while (i < len)
	{
		if (!(ft_isdigit(str[i]) || ft_isspace(str[i]) || str[i] == '-'))
			return (0);
		if (ft_isspace(str[i]))
			nspace++;
		i++;
	}
	return (nspace);
}

int	parse_int_array(char *str, int *array[])
{
	int		i;
	int		nint;
	char	**int_strs;

	i = 0;
	nint = is_num_str(str);
	if (nint <= 0)
		return (-1);
	*array = (int *)malloc(sizeof(int) * (++nint));
	if (!*array)
		return (-1);
	int_strs = ft_split(str, ' ');
	if (!int_strs)
		return (-1);
	i = -1;
	while (int_strs[++i])
	{
		(*array)[i] = ft_atoi(int_strs[i]);
		free(int_strs[i]);
	}
	free(int_strs);
	return (nint);
}
