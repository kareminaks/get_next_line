/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenia <ksenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:17:45 by kkaremin          #+#    #+#             */
/*   Updated: 2023/04/21 16:16:34 by ksenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define MAX_FD 256

void	append(char **str, char *src, size_t len)
{
	size_t	strlen;
	char	*res;

	if (!*str)
	{
		res = malloc(len + 1);
		ft_memcpy(res, src, len);
		res[len] = 0;
		*str = res;
		return ;
	}
	strlen = ft_strlen(*str);
	res = malloc(strlen + len + 1);
	ft_memcpy(res, *str, strlen);
	ft_memcpy(res + strlen, src, len);
	res[strlen + len] = 0;
	free(*str);
	*str = res;
}

int	contains(char *str, char c)
{
	int	index;

	index = ft_index_of(str, c);
	return (index >= 0);
}

char	*get_next_line_with_buf(char* buf, char** bufs_fd, int fd)
{
	int			bytes_read;

	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		append(bufs_fd, buf, bytes_read);
		if (contains(*bufs_fd, '\n'))
			return (ft_truncate(bufs_fd));
	}
	if (bytes_read < 0)
		return (0);
	return (ft_truncate(bufs_fd));
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*bufs[MAX_FD];

	if (fd < 0 || fd >= MAX_FD)
		return (0);

	buf = malloc(BUFFER_SIZE);
	char* result = get_next_line_with_buf(buf, &bufs[fd], fd);
	if (bufs[fd] != 0 && (!result || *bufs[fd] == 0)) {
		free(bufs[fd]);
		bufs[fd] = 0;
	}
	free(buf);
	return result;
}
