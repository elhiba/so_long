/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:28:25 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/05 18:04:52 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_window(t_game *vars)
{
	char	**tmp;

	tmp = vars->map;
	while (*tmp)
		(1) && (free(*tmp), tmp++);
	free(vars->map);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->collectible);
	mlx_destroy_image(vars->mlx, vars->ground);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->player.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	put_map(t_game **vars, char **map)
{
	int (x), (y);
	y = 0;
	load_images(*vars);
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == '0')
				put_ground(*vars, x * X_IMG, y * Y_IMG);
			else if (map[y][x] == '1')
				put_wall(*vars, x * X_IMG, y * Y_IMG);
			else if (map[y][x] == 'E')
				put_exit(*vars, x * X_IMG, y * Y_IMG);
			else if (map[y][x] == 'C')
				put_collectible(*vars, x * X_IMG, y * Y_IMG);
			else if (map[y][x] == 'P')
				put_player(*vars, x, y);
			(1) && (++x, (*vars)->x_map_len = x);
		}
		(1) && (++y, (*vars)->y_map_len = y);
	}
}

int	move_player(int keys, t_game *vars)
{
	if (keys == ESC)
		close_window(vars);
	player_move(keys, vars);
	return (0);
}

int	sus(t_game *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x] && vars->map[y][x] != '\n')
		{
			if (vars->map[y][x] != '1' && vars->map[y][x] != 'F'
				&& vars->map[y][x] != 'E' && vars->map[y][x] != 'C'
				&& vars->map[y][x] != '0' && vars->map[y][x] != 'P')
			{
				ft_putstr_fd("Error\n===\tHave you seen \
chickens in cloud?!\n", 2);
				autofree(vars->map, NULL);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	gui(t_game *vars, char **map)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->x_window,
			vars->y_window, "so_long");
	put_map(&vars, map);
	vars->map = map;
	mlx_hook(vars->win, 2, 1L << 0, move_player, vars);
	mlx_hook(vars->win, 17, 1L << 17, close_window, vars);
	mlx_loop(vars->mlx);
}
