/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:21:55 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/06 12:24:37 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fn_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		tmp = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = tmp;
		i++;
	}
}

char	*integer_to_str(t_number *n, int HEX_CAPITAL, char *carray)
{
	size_t	i;
	char	*symbol;

	if (HEX_CAPITAL)
		symbol = SYMBOL_U;
	else
		symbol = SYMBOL_L;
	i = 0;
	if (n->num == 0)
		carray[i++] = '0';
	while (n->num > 0)
	{
		carray[i] = symbol[n->num % n->base];
		n->num /= n->base;
		i++;
	}
	if (n->sign && n->base == 10)
		carray[i++] = n->sign;
	else if (n->base == 16 && i > 8)
		i = 8;
	carray[i] = '\0';
	fn_strrev(carray);
	return (carray);
}

char	*integer_to_str_wrapper(t_number *n, long long value, char chex,
		char *carray)
{
	char	*str;

	if (value < 0)
	{
		n->num = -value;
		n->sign = '-';
	}
	else
	{
		n->num = value;
		n->sign = '\0';
	}
	str = integer_to_str(n, chex == 'X', carray);
	return (str);
}

char	*integer_to_ptr(t_number *n, int HEX_CAPITAL, char *carray)
{
	size_t	i;
	char	*symbol;

	if (HEX_CAPITAL)
		symbol = SYMBOL_U;
	else
		symbol = SYMBOL_L;
	i = 0;
	while (n->num > 0)
	{
		carray[i] = symbol[n->num % n->base];
		n->num /= n->base;
		i++;
	}
	if (n->base == 16)
	{
		carray[i++] = 'x';
		carray[i++] = '0';
	}
	carray[i] = '\0';
	fn_strrev(carray);
	return (carray);
}
