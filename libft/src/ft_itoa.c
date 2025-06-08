/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:03:56 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 18:17:55 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt++;
		n *= -1;
	}
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

static int	init_na(const int n, char **na)
{
	int	ndigit;

	ndigit = count_digit(n);
	*na = (char *)malloc(sizeof(char) * (ndigit + 1));
	if (!*na)
		return (-1);
	return (ndigit);
}

static char	*get_empty_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static char	*get_default_values(int n)
{
	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	else if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*na;
	int		ndigit;

	if (n == 0 || n == INT_MIN)
		return (get_default_values(n));
	ndigit = init_na(n, &na);
	if (ndigit < 0)
		return (get_empty_str());
	na[ndigit] = '\0';
	if (n < 0)
	{
		na[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		na[--ndigit] = (n % 10) + '0';
		n /= 10;
	}
	return (na);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("(0) %s\n", ft_itoa(INT_MAX));
// 	printf("(1) %s\n", ft_itoa(INT_MIN));
// 	printf("(2) %s\n", ft_itoa(42));
// 	printf("(3) %s\n", ft_itoa(-2424));
// 	printf("(4) %s\n", ft_itoa(0));
// 	printf("(5) %s\n", ft_itoa(1234567));
// 	return (0);
// }
