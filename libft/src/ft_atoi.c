/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:00:07 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 17:12:21 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_neg(const char **str)
{
	int	neg;

	neg = 0;
	while ((9 <= (unsigned char)**str && (unsigned char)**str <= 13)
		|| (unsigned char)**str == ' ')
		(*str)++;
	if ((unsigned char)**str == '+' || (unsigned char)**str == '-')
	{
		neg = ((unsigned char)**str == '-');
		(*str)++;
	}
	return (neg);
}

static void	get_cutoff_and_cutlim(unsigned long *cutoff, int *cutlim, int neg,
		int base)
{
	if (neg)
		*cutoff = -(unsigned long)LONG_MIN;
	else
		*cutoff = (unsigned long)LONG_MAX;
	*cutlim = *cutoff % base;
	*cutoff /= base;
}

static long	finalize_acc(unsigned long acc, int neg, int any)
{
	if (any < 0)
	{
		if (neg)
			acc = -(unsigned long)LONG_MIN;
		else
			acc = (unsigned long)LONG_MAX;
	}
	else if (!any)
		acc = 0;
	if (neg)
		acc *= -1;
	return ((long)acc);
}

static long	ft_strtol(const char *str, char **endptr, int base)
{
	unsigned long	acc;
	unsigned long	cutoff;
	int				cutlim;
	int				neg;
	int				any;

	(void)endptr;
	(void)base;
	acc = 0;
	any = 0;
	neg = is_neg(&str);
	get_cutoff_and_cutlim(&cutoff, &cutlim, neg, base);
	while (*str && ft_isdigit(*str))
	{
		if (acc > cutoff || (acc == cutoff && *str > cutlim))
			any = -1;
		else
		{
			any = 1;
			acc = base * acc + (*str - '0');
		}
		str++;
	}
	acc = finalize_acc(acc, neg, any);
	return (acc);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str, (char **) NULL, 10));
}

// #include <stdio.h>
// #include <stdlib.h>

// int test_atoi(int i, char *str)
// {
// 	printf("(%d) ft_atoi(%s) = %d", i, str, ft_atoi(str));
// 	if (ft_atoi(str) == atoi(str))
// 		printf("\t\t=> ✅AC (expected atoi(%s) = %d)\n", str, atoi(str));
// 	return (0);
// }

// int	main(void)
// {
// 	char	test_0[] = "   +42";
// 	char	test_1[] = "2147483647";
// 	char	test_2[] = "-0";
// 	char	test_3[] = "-2424abc";
// 	char	test_4[] = "-2147483648";
// 	char	test_5[] = "2147483648";
// 	char	test_6[] = "9223372036854775807";
// 	char	test_7[] = "9223372036854775808";
// 	char	test_8[] = "-9223372036854775808";
// 	char	test_9[] = "-9223372036854775809";
// 	char	test_10[] = "     +10000000000";
// 	char	test_11[] = "     +1145141919810";

// 	printf("(0) ft_atoi(%s) = %d\n", test_0, ft_atoi(test_0));
// 	printf("(1) ft_atoi(%s) = %d\n", test_1, ft_atoi(test_1));
// 	printf("(2) ft_atoi(%s) = %d\n", test_2, ft_atoi(test_2));
// 	printf("(3) ft_atoi(%s) = %d\n", test_3, ft_atoi(test_3));
// 	printf("(4) ft_atoi(%s) = %d\n", test_4, ft_atoi(test_4));
// 	printf("(5) ft_atoi(%s) = %d\n", test_5, ft_atoi(test_5));
// 	printf("(6) ft_atoi(%s) = %d\n", test_6, ft_atoi(test_6));
// 	printf("(7) ft_atoi(%s) = %d\n", test_7, ft_atoi(test_7));
// 	printf("(8) ft_atoi(%s) = %d\n", test_8, ft_atoi(test_8));
// 	printf("(9) ft_atoi(%s) = %d\n", test_9, ft_atoi(test_9));
// 	printf("(10) ft_atoi(%s) = %d", test_10, ft_atoi(test_10));
// 	if (ft_atoi(test_10) == atoi(test_10))
// 		printf(" => AC (expected atoi(%s) = %d)\n", test_10, atoi(test_10));
// 	test_atoi(11, test_11);
// 	test_atoi(12, "     +1145141919");
// 	return (0);
// }
