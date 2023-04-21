/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:17:45 by kkaremin          #+#    #+#             */
/*   Updated: 2023/04/21 13:59:30 by kkaremin         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*bufs[MAX_FD];
	char		*buf;
	int			bytes_read;

	buf = malloc(BUFFER_SIZE);
	if (fd < 0 || fd >= MAX_FD)
	{
		free(buf);
		return (0);
	}
	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		append(&bufs[fd], buf, bytes_read);
		if (contains(bufs[fd], '\n'))
		{
			free(buf);
			return (ft_truncate(&bufs[fd]));
		}
	}
	if (bytes_read < 0)
	{
		free(bufs[fd]);
		bufs[fd] = 0;
		free(buf);
		return (0);
	}
	free(buf);
	return (ft_truncate(&bufs[fd]));
}
