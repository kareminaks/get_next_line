#include <unistd.h>
#include <stdlib.h>
#include "stdio.h"

char *get_next_line(int fd);

char	*ft_cut(char *str, size_t len);

void	ft_memcpy(char *dst, char *src, size_t len);

int	ft_index_of(char *str, char c);

size_t	ft_strlen(char *str);

char	*ft_truncate(char **buf);