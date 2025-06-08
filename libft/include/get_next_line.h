/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:55:58 by fnakamur          #+#    #+#             */
/*   Updated: 2025/04/30 15:49:19 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# define FT_EOF -130
# define FT_RDERR -129

typedef struct s_FILE
{
	int		fd;
	char	*buf;
	size_t	buf_size;
	size_t	pos;
	size_t	len;
	int		eof;
	int		error;
}			t_FILE;

typedef struct s_BUFFER
{
	char	*data;
	size_t	len;
	size_t	size;
}			t_BUFFER;

t_FILE		*ft_fopen_fd(const int fd);
void		ft_fclose(t_FILE **fp);
int			ft_getc(t_FILE *fp);
int			ft_putc(t_BUFFER *buffer, char c);
char		*get_next_line(int fd);
int			gnl_fclose(void);

#endif
