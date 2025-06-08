/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:56:16 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/28 23:59:24 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_FILE	*g_fp = NULL;

int	ft_getc(t_FILE *fp)
{
	ssize_t	bytes_read;

	if (!fp)
		return (FT_EOF);
	if (fp->pos >= fp->len)
	{
		bytes_read = read(fp->fd, fp->buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			fp->error = 1;
			return (FT_RDERR);
		}
		if (bytes_read == 0)
		{
			fp->eof = 1;
			return (FT_EOF);
		}
		fp->len = (size_t)bytes_read;
		fp->pos = 0;
	}
	return ((unsigned char)fp->buf[fp->pos++]);
}

int	ft_putc(t_BUFFER *buffer, char c)
{
	char	*tmp;
	size_t	i;

	if (buffer->len + 1 > buffer->size)
	{
		buffer->size = (buffer->size + 1) * 2;
		tmp = (char *)malloc(sizeof(char) * buffer->size);
		if (!tmp)
			return (free(buffer->data), -1);
		i = 0;
		while (i < buffer->len)
		{
			tmp[i] = buffer->data[i];
			i++;
		}
		free(buffer->data);
		buffer->data = tmp;
	}
	buffer->data[buffer->len] = c;
	buffer->len++;
	return (0);
}

char	*get_next_line(int fd)
{
	t_BUFFER	out_buf;
	int			c;

	if (!g_fp)
		g_fp = ft_fopen_fd(fd);
	out_buf.data = NULL;
	out_buf.len = 0;
	out_buf.size = 0;
	while (g_fp != NULL)
	{
		c = ft_getc(g_fp);
		if (c == '\n' && ft_putc(&out_buf, c) >= 0)
			break ;
		else if (g_fp->eof)
		{
			ft_fclose(&g_fp);
			break ;
		}
		else if (g_fp->error || ft_putc(&out_buf, c) < 0)
			return (ft_fclose(&g_fp), NULL);
	}
	if (out_buf.len > 0)
		ft_putc(&out_buf, '\0');
	return (out_buf.data);
}

int	gnl_fclose(void)
{
	ft_fclose(&g_fp);
	return (EXIT_SUCCESS);
}
