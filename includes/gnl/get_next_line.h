/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:36:15 by moel-hib          #+#    #+#             */
/*   Updated: 2025/02/19 10:29:59 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*gnl_ft_memchr(void *s, int c, ssize_t n, char **remain);
char	*to_do(char *buff, ssize_t r_len, int *check);
size_t	gnl_ft_strlen(char *s);
char	*gnl_ft_strchr(void *s, int c);
void	*gnl_ft_memcpy(void *dest, void *src, size_t n);
char	*gnl_ft_free(char **str);
char	*gnl_ft_strjoin(char *s1, char *s2);

#endif
