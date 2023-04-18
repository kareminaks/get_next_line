#include "get_next_line.h"

#define MAX_FD 256

void	append(char **str, char *src, size_t len)
{
	size_t	strlen;
	char	*res;

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
	static char *bufs[MAX_FD];
	char buf[BUFFER_SIZE];
	int bytes_read;

	if (fd < 0 || fd >= MAX_FD)
		return (0);

	if (!bufs[fd])
	{
		bufs[fd] = malloc(1);
		bufs[fd][0] = 0;
	}

	while (1)
	{
        bytes_read = read(fd, buf, BUFFER_SIZE)
        if (bytes_read <= 0)
            break;
		append(&bufs[fd], buf, bytes_read);
		if (contains(bufs[fd], '\n'))
		{
			return (ft_truncate(&bufs[fd]));
		}
	}
	if (bytes_read < 0)
		return (0);

	return (ft_truncate(&bufs[fd]));
}
