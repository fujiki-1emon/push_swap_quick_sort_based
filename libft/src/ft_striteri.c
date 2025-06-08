/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:07:32 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:07:34 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void my_toupper(unsigned int idx, char *c)
// {
// 	(void)idx;
// 	if ('a' <= *c && *c <= 'z')
// 		*c = *c - 'a' + 'A';
// }

// #include <stdio.h>
// int main(void)
// {
// 	char test_0[] = "Hello, world!";
// 	printf("(0)\n");
// 	printf("ft_striteri(%s)", test_0);
// 	ft_striteri(test_0, &my_toupper);
// 	printf(" -> %s\n", test_0);
// 	return (0);
// }
