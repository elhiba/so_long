/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:29:17 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/06 01:33:19 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	open_door(t_game *vars)
{
	if (vars->player.collectible == vars->player.collected)
	{
		mlx_destroy_image(vars->mlx, vars->exit);
		vars->exit = mlx_xpm_file_to_image(vars->mlx,
				EXIT_OPEN, &vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit,
			vars->exit_x * X_IMG, vars->exit_y * Y_IMG);
	}
}

void	collectible(int key, t_game *vars)
{
	if ((key == UP || key == UP_W)
		&& vars->map[vars->player.y_map - 1][vars->player.x_map] == 'E'
		&& vars->player.collectible == vars->player.collected)
		(1) && (ft_printf("Victory! (ﾉ◕ヮ◕)ﾉ*:･ﾟYou triumphed \
in %i steps ✧ !\n", vars->player.move), close_window(vars));
	if ((key == DOWN || key == DOWN_S)
		&& vars->map[vars->player.y_map + 1][vars->player.x_map] == 'E'
		&& vars->player.collectible == vars->player.collected)
		(1) && (ft_printf("Victory! (ﾉ◕ヮ◕)ﾉ*:･ﾟYou triumphed \
in %i steps ✧ !\n", vars->player.move), close_window(vars));
	if ((key == RIGHT || key == RIGHT_D)
		&& vars->map[vars->player.y_map][vars->player.x_map + 1] == 'E'
		&& vars->player.collectible == vars->player.collected)
		(1) && (ft_printf("Victory! (ﾉ◕ヮ◕)ﾉ*:･ﾟYou triumphed \
in %i steps ✧ !\n", vars->player.move), close_window(vars));
	if ((key == LEFT || key == LEFT_A)
		&& vars->map[vars->player.y_map][vars->player.x_map - 1] == 'E'
		&& vars->player.collectible == vars->player.collected)
		(1) && (ft_printf("Victory! (ﾉ◕ヮ◕)ﾉ*:･ﾟYou triumphed \
in %i steps ✧ !\n", vars->player.move), close_window(vars));
}

int	map_visulizer(int key, t_game *vars)
{
	collectible(key, vars);
	if (key == UP || key == UP_W)
		if (vars->map[vars->player.y_map - 1][vars->player.x_map] != '1'
			&& vars->map[vars->player.y_map - 1][vars->player.x_map] != 'E')
			return (vars->player.y_map -= 1);
	if (key == DOWN || key == DOWN_S)
		if (vars->map[vars->player.y_map + 1][vars->player.x_map] != '1'
			&& vars->map[vars->player.y_map + 1][vars->player.x_map] != 'E')
			return (vars->player.y_map += 1);
	if (key == LEFT || key == LEFT_A)
		if (vars->map[vars->player.y_map][vars->player.x_map - 1] != '1'
			&& vars->map[vars->player.y_map][vars->player.x_map - 1] != 'E')
			return (vars->player.x_map -= 1);
	if (key == RIGHT || key == RIGHT_D)
		if (vars->map[vars->player.y_map][vars->player.x_map + 1] != '1'
			&& vars->map[vars->player.y_map][vars->player.x_map + 1] != 'E')
			return (vars->player.x_map += 1);
	return (0);
}

void	player_move(int key, t_game *vars)
{
	if (key)
	{
		if (key == UP || key == UP_W)
			player_up(key, vars);
		else if (key == DOWN || key == DOWN_S)
			player_down(key, vars);
		else if (key == LEFT || key == LEFT_A)
			player_left(key, vars);
		else if (key == RIGHT || key == RIGHT_D)
			player_right(key, vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img,
			vars->player.x, vars->player.y);
	}
	if (vars->map[vars->player.y_map][vars->player.x_map] == 'C')
	{
		vars->map[vars->player.y_map][vars->player.x_map] = '0';
		++vars->player.collected;
		open_door(vars);
	}
}
