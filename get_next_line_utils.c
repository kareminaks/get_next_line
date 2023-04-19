/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:17:42 by kkaremin          #+#    #+#             */
/*   Updated: 2023/04/19 17:10:30 by kkaremin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut(char *str, size_t len)
{
	char	*cut;
	size_t	i;

	cut = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		cut[i] = str[i];
		i++;
	}
	cut[len] = 0;
	free(str);
	return (cut);
}

void	ft_memcpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

int	ft_index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		str++;
		i++;
	}
	if (!c)
		return (i);
	return (-1);
}

size_t	ft_strlen(char *str)
{
	if (!str)
		return (0);
	return (ft_index_of(str, '\0'));
}

char	*ft_truncate(char **buf)
{
	size_t	len;
	char	*result;
	char	*new_buf;

	len = ft_index_of(*buf, '\n') + 1;
	if (len < 1 && ft_strlen(*buf) == 0)
		return (0);
	if (len <= 1)
	{
		result = ft_cut(*buf, ft_strlen(*buf));
		free(*buf);
		*buf = 0;
		return (result);
	}
	result = ft_cut(*buf, len);
	new_buf = ft_cut(*buf + len, ft_strlen(*buf) - len);
	free(*buf);
	*buf = new_buf;
	return (result);
}
