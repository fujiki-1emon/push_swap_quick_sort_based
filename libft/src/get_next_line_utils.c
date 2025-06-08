/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:56:28 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/30 16:06:02 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_FILE	*ft_fopen_fd(const int fd)
{
	t_FILE	*fp;

	if (BUFFER_SIZE < 0)
		return (NULL);
	fp = (t_FILE *)malloc(sizeof(t_FILE));
	if (!fp)
		return (NULL);
	fp->fd = fd;
	fp->buf_size = BUFFER_SIZE;
	fp->buf = (char *)malloc(sizeof(char) * fp->buf_size);
	if (!fp->buf)
		return (free(fp), NULL);
	fp->pos = 0;
	fp->len = 0;
	fp->eof = 0;
	fp->error = 0;
	return (fp);
}

void	ft_fclose(t_FILE **fp)
{
	if (!*fp)
		return ;
	if ((*fp)->buf)
		free((*fp)->buf);
	free(*fp);
	*fp = NULL;
}
