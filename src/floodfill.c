/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:23:32 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/06 01:18:10 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(t_game *vars, char **arr, int y, int x)
{
	if (y < 0 || y >= vars->y_map_len || x < 0 || x >= vars->x_map_len)
		return ;
	if (arr[y][x] == 'F' || arr[y][x] == '1' || arr[y][x] == 'E')
		return ;
	arr[y][x] = 'F';
	flood_fill(vars, arr, y, x - 1);
	flood_fill(vars, arr, y, x + 1);
	flood_fill(vars, arr, y - 1, x);
	flood_fill(vars, arr, y + 1, x);
}

void	valid_path(t_game *vars, char **lines)
{
	int		i;

	char **(tab), **(tmp);
	(1) && (i = 0, tab = malloc(sizeof(char *) * (vars->line_len + 1)));
	if (!tab)
		return ;
	while (i < vars->y_map_len)
		(1) && (tab[i] = ft_strdup(lines[i]), i++);
	tab[vars->y_map_len] = NULL;
	flood_fill(vars, tab, vars->player.y_map, vars->player.x_map);
	(1) && (i = 0, tmp = tab);
	while (tab[i])
	{
		if (ft_strchr(tab[i], 'C'))
		{
			while (*tmp)
				(1) && (free(*tmp), tmp++);
			(1) && (free(tab), autofree(lines, "FLOOD"));
		}
		i++;
	}
	while (*tmp)
		(1) && (free(*tmp), tmp++);
	free(tab);
}
