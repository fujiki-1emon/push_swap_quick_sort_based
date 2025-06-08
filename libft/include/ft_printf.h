/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:36:32 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/06 12:25:27 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SYMBOL_U "0123456789ABCDEF"
# define SYMBOL_L "0123456789abcdef"

typedef struct s_number
{
	unsigned long long	num;
	char				sign;
	int					base;
}						t_number;

int						ft_printf(const char *format, ...);
int						parse_format(const char *str, va_list args, int *i,
							int *start_i);
int						parse_string(const char *str, va_list args);
int						parse_integer(const char *str, va_list args);
int						parse_pointer(const char *str, va_list args);
char					*integer_to_str_wrapper(t_number *n, long long value,
							char chex, char *carray);
int						parse_pointer(const char *str, va_list args);
char					*integer_to_str(t_number *n, int HEX_CAPITAL,
							char *carray);
char					*integer_to_ptr(t_number *n, int HEX_CAPITAL,
							char *carray);
#endif
