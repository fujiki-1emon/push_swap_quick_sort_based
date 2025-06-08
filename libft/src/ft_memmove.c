/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:06:09 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/25 11:06:11 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (len == 0 || src == dst)
		return (dst);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	if (d <= s || s + len <= d)
	{
		while (i++ < len)
			d[i - 1] = s[i - 1];
	}
	else if (s < d && d < s + len)
	{
		while (0 < len--)
			d[len] = s[len];
	}
	return (dst);
}

// #include <assert.h>
// #include <stdio.h>
// #include <string.h>

// static void	test_non_overlap(void)
// {
// 	char	dst1[20] = "AAAAAAAAAAAAAAAA";
// 	char	src1[20] = "1234567890";
// 	char	dst2[20] = "AAAAAAAAAAAAAAAA";
// 	char	src2[20] = "1234567890";

// 	ft_memmove(dst1, src1, 10);
// 	assert(memcmp(dst1, src1, 10) == 0);
// 	ft_memmove(dst2 + 10, src2, 10);
// 	assert(memcmp(dst2 + 10, src2, 10) == 0);
// 	printf("test_non_overlap passed.\n");
// }

// static void	test_forward_overlap(void)
// {
// 	char	buf[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// 	// src = buf+5 ("FGHIJ...") → dst = buf ("ABCDE...") と前方オーバーラップ
// 	ft_memmove(buf, buf + 5, 10);
// 	// 期待: buf[0..9] == 元 buf[5..14]
// 	assert(memcmp(buf, "FGHIJKLMNO", 10) == 0);
// 	printf("test_forward_overlap passed.\n");
// }

// static void	test_backward_overlap(void)
// {
// 	char	buf[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// 	// src = buf ("ABCDE...") → dst = buf+5 ("FGHIJ...") と後方オーバーラップ
// 	// → 末尾から逆向きコピーしないと元データを壊すケース
// 	ft_memmove(buf + 5, buf, 10);
// 	// 期待: buf[5..14] == "ABCDEFGHIJ"
// 	assert(memcmp(buf + 5, "ABCDEFGHIJ", 10) == 0);
// 	printf("test_backward_overlap passed\n");
// }

// static void	test_same_region(void)
// {
// 	char	buf1[20] = "HELLOWORLD";

// 	// dst == src の場合は何もしない（そのまま同じ文字列）
// 	ft_memmove(buf1, buf1, strlen(buf1));
// 	assert(strcmp(buf1, "HELLOWORLD") == 0);
// 	printf("test_same_region passed.\n");
// }

// int	main(void)
// {
// 	test_non_overlap();
// 	test_forward_overlap();
// 	test_backward_overlap();
// 	test_same_region();
// 	printf("All ft_memmove tests passed.\n");
// 	return (0);
// }
