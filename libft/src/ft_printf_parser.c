/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:18:16 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/07 14:48:22 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(const char *str, va_list args, int *i, int *start_i)
{
	int	bytes;

	if (!*(str + 1))
		return (-EXIT_FAILURE);
	else if (*(str + 1) == '%')
		bytes = (++(*i), *start_i = ++(*i), ft_putchar_fd('%', 1), 1);
	else
	{
		*start_i = ++(*i);
		if (ft_strchr("duixX", *(str + 1)))
			bytes = (++(*start_i), parse_integer(str + 1, args));
		else if (*(str + 1) == 'c')
			bytes = (++(*start_i), parse_string(str + 1, args));
		else if (*(str + 1) == 's')
			bytes = (++(*start_i), parse_string(str + 1, args));
		else if (*(str + 1) == 'p')
			bytes = (++(*start_i), parse_pointer(str + 1, args));
		else if (*str == '%')
			bytes = (ft_putchar_fd('%', 1), 1);
		else
			bytes = (++(*start_i), ft_putchar_fd(*(str + 1), 1), 1);
	}
	return (bytes);
}

int	parse_string(const char *str, va_list args)
{
	char	c;
	char	*s;

	if (*str == 'c')
	{
		c = va_arg(args, unsigned);
		return (ft_putchar_fd(c, 1), 1);
	}
	if (*str == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			return (ft_putstr_fd("(null)", 1), 6);
		else
			return (ft_putstr_fd(s, 1), (int)ft_strlen(s));
	}
	return (0);
}

int	parse_integer(const char *str, va_list args)
{
	t_number	n;
	long long	value;
	char		carray[30];
	char		*str_out;

	value = 0;
	n.base = 10;
	if (*str == 'd' || *str == 'i')
		value = (long long)va_arg(args, int);
	else if (*str == 'u')
		value = (long long)va_arg(args, unsigned int);
	else if (*str == 'x' || *str == 'X')
	{
		value = (long long)va_arg(args, unsigned int);
		n.base = 16;
	}
	str_out = integer_to_str_wrapper(&n, value, *str, carray);
	return (ft_putstr_fd(str_out, 1), (int)ft_strlen(str_out));
}

int	parse_pointer(const char *str, va_list args)
{
	t_number			n;
	unsigned long long	value;
	char				carray[30];
	char				*str_out;

	n.base = 16;
	value = (unsigned long long)va_arg(args, uintptr_t);
	if (value == 0)
		return (ft_putstr_fd("(nil)", 1), 5);
	n.num = value;
	str_out = integer_to_ptr(&n, *str == 'X', carray);
	return (ft_putstr_fd(str_out, 1), (int)ft_strlen(str_out));
}
