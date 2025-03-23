/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:51:35 by moel-hib          #+#    #+#             */
/*   Updated: 2025/02/09 15:49:15 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

char	*gnl_ft_strchr(void *s, int c)
{
	size_t	i;
	char	*src;

	if (!s)
		return (NULL);
	i = 0;
	src = (char *)s;
	while (src[i])
	{
		if (src[i] == c)
			return (&src[i]);
		i++;
	}
	return (0);
}

void	*gnl_ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*src;
	int		total_len;
	int		len_s1;
	int		len_s2;

	if (!s2)
		return (NULL);
	len_s1 = gnl_ft_strlen(s1);
	len_s2 = gnl_ft_strlen(s2);
	total_len = len_s1 + len_s2;
	src = malloc(total_len + 1);
	if (!src)
		return (NULL);
	gnl_ft_memcpy(src, s1, len_s1);
	gnl_ft_memcpy(src + len_s1, s2, len_s2);
	src[total_len] = '\0';
	gnl_ft_free(&s1);
	gnl_ft_free(&s2);
	return (src);
}

char	*gnl_ft_free(char **str)
{
	if (*str == NULL)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}
