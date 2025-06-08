/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:19:48 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/06 12:24:11 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fn_vprintf(const char *str, va_list args)
{
	int	bytes_written;
	int	bytes_parsed;
	int	i;
	int	start_i;

	bytes_written = 0;
	i = 0;
	start_i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			i++;
		if (write(1, &str[start_i], i - start_i) < 0)
			return (-EXIT_FAILURE);
		bytes_written += i - start_i;
		if (str[i] == '\0')
			return (va_end(args), bytes_written);
		bytes_parsed = parse_format(&str[i], args, &i, &start_i);
		if (bytes_parsed < 0)
			return (-EXIT_FAILURE);
		else
			bytes_written += bytes_parsed;
	}
	return (bytes_written);
}

int	ft_printf(const char *format, ...)
{
	int			bytes_written;
	va_list		args;
	const char	*fmt;
	size_t		cnt;

	cnt = 0;
	fmt = format;
	if (!fmt)
		return (-EXIT_FAILURE);
	while (*fmt)
		cnt += (*fmt++ == '%');
	if (cnt > INT_MAX)
		return (write(1, "Error\n", 6), -EXIT_FAILURE);
	va_start(args, format);
	bytes_written = fn_vprintf(format, args);
	va_end(args);
	return (bytes_written);
}
