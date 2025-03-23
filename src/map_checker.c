/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:49:53 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/06 17:11:17 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	extension_map(char *extension)
{
	int	i;

	i = 0;
	while (extension[i])
		i++;
	if (extension[i] == '\0')
	{
		if (extension[i - 1] == 'r')
			if (extension[i - 2] == 'e')
				if (extension[i - 3] == 'b')
					if (extension[i - 4] == '.')
							if (ft_isalnum(extension[i - 5]))
						return (1);
	}
	return (0);
}

int	isrectangle_map(char **lines)
{
	int (i), (len), (tmp_len);
	(1) && (i = 0, len = ft_strlen(lines[i]));
	if (ft_strchr(lines[i], '\n'))
		len--;
	tmp_len = len;
	while (lines[i] && len == tmp_len)
	{
		tmp_len = ft_strlen(lines[i]);
		if (ft_strchr(lines[i], '\n'))
			tmp_len--;
		if (tmp_len != len)
			autofree(lines, "RECTANGLE");
		i++;
	}
	return (1);
}

int	isclosed_map(char **lines)
{
	char	**ptr;

	int (i), (line_y), (line_x);
	ptr = lines;
	i = 0;
	line_y = line_counter(lines);
	line_x = ft_strlen(*ptr);
	while (ptr[0][i])
	{
		if (ptr[0][i] == '\n')
			break ;
		if (ptr[0][i] != '1' || ptr[line_y - 1][i] != '1')
			autofree(lines, "NOT_MAP");
		i++;
	}
	i = 0;
	while (ptr[i])
	{
		if (ptr[i][0] != '1' || ptr[i][line_x - 2] != '1')
			autofree(lines, "NOT_MAP");
		i++;
	}
	return (1);
}

void	iscompleted_map(char **lines, t_game *vars)
{
	int (e), (p), (c), (y), (x);
	(1) && (y = 0, x = 0, e = 0, p = 0, c = 0);
	while (lines[y])
	{
		x = 0;
		while (lines[y][x] && lines[y][x] != '\n')
		{
			if (lines[y][x] == 'P')
				(1) && (++p, vars->player.x_map = x, vars->player.y_map = y);
			if (lines[y][x] == 'E')
				(1) && (++e, vars->exit_x = x, vars->exit_y = y);
			if (lines[y][x] == 'C')
				(1) && (++c, vars->player.collectible = c);
			x++;
		}
		y++;
	}
	(1) && (vars->x_map_len = x, vars->y_map_len = y);
	(1) && (vars->x_window = x * X_IMG, vars->y_window = y * Y_IMG);
	if (p > 1 || p == 0)
		autofree(lines, "P");
	if (e > 1 || e == 0)
		autofree(lines, "E");
	if (c == 0)
		autofree(lines, "C");
}

char	**isvalid_map(char *map, t_game *vars)
{
	char	**lines;

	int (fd), (i);
	(1) && (i = 0, fd = open(map, O_RDONLY));
	if (fd <= 0)
		autofree(NULL, "N_FOUND");
	lines = malloc(sizeof(char *) * (vars->line_len + 1));
	if (!lines)
		exit(1);
	while (1)
	{
		lines[i] = get_next_line(fd);
		if (!lines[i])
			break ;
		i++;
	}
	(1) && (lines[i] = NULL, close(fd));
	if (!*lines)
		autofree(lines, "EMPTY");
	(1) && (isrectangle_map(lines), isclosed_map(lines));
	iscompleted_map(lines, vars);
	valid_path(vars, lines);
	vars->map = lines;
	(1) && (sus(vars), file_failures(lines));
	return (lines);
}
