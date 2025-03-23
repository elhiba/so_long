/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:51:14 by moel-hib          #+#    #+#             */
/*   Updated: 2025/02/09 15:48:52 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *r_out, ssize_t r_file)
{
	char	*buff;

	r_file = 1;
	while (r_file > 0)
	{
		if (r_out == NULL)
		{
			r_out = malloc(1);
			if (!r_out)
				return (NULL);
			r_out[0] = '\0';
		}
		buff = malloc((size_t)BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		r_file = read(fd, buff, BUFFER_SIZE);
		if (r_file < 0)
			return (gnl_ft_free(&buff), gnl_ft_free(&r_out), NULL);
		if (r_file == 0 && *r_out == '\0')
			return (free(buff), free(r_out), NULL);
		(1) && (buff[r_file] = 0, r_out = gnl_ft_strjoin(r_out, buff));
		if (gnl_ft_strchr(r_out, '\n'))
			break ;
	}
	return (r_out);
}

char	*ft_line(char *r_in)
{
	int		i;
	char	*buff;

	i = 0;
	if (!r_in[i])
	{
		gnl_ft_free(&r_in);
		return (NULL);
	}
	while (r_in[i] && r_in[i] != '\n')
		i++;
	buff = malloc(i + 2);
	if (!buff)
		return (NULL);
	gnl_ft_memcpy(buff, r_in, i);
	if (r_in[i] == '\n')
		buff[i++] = '\n';
	buff[i] = 0;
	return (buff);
}

char	*ft_next(char **buff)
{
	char	(*remain);

	int (i), (j);
	(1) && (i = 0, j = 0);
	while (*buff != NULL && (*buff)[i])
	{
		if ((*buff)[i] == '\n')
		{
			while ((*buff)[i + j])
				j++;
			break ;
		}
		i++;
	}
	remain = malloc(j + 1);
	if (!remain)
		return (NULL);
	i++;
	gnl_ft_memcpy(remain, *buff + i, j);
	remain[j] = 0;
	gnl_ft_free(buff);
	if (j == 0)
		return (gnl_ft_free(&remain), NULL);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remain = read_file(fd, remain, 1);
	if (!remain)
		return (NULL);
	line = ft_line(remain);
	if (line == NULL)
		return (gnl_ft_free(&line), NULL);
	remain = ft_next(&remain);
	return (line);
}
