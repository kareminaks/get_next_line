/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:17:51 by kkaremin          #+#    #+#             */
/*   Updated: 2023/04/19 17:39:41 by kkaremin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
#   define BUFFER_SIZE 256
#endif 

char    *get_next_line(int fd);
char    *ft_cut(char   *str, size_t    len);
char    *ft_truncate(char  **buf);

void    ft_memcpy(char *dst, char  *src, size_t    len);

int ft_index_of(char    *str, char  c);

size_t  ft_strlen(char   *str);

#endif