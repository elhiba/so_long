/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:10:33 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/05 17:11:55 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	put_collectible(t_game *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->collectible, x, y);
}

void	put_wall(t_game *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->wall, x, y);
}

void	put_ground(t_game *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->ground, x, y);
}

void	put_exit(t_game *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->exit, x, y);
}

void	put_player(t_game *vars, int x, int y)
{
	t_player	p;

	ft_bzero(&p, sizeof(t_player));
	vars->player.img_path = PLAYER;
	if (!vars->player.img)
		vars->player.img = mlx_xpm_file_to_image(vars->mlx,
				vars->player.img_path, &vars->img_width, &vars->img_height);
	(1) && (vars->player.x_map = x, vars->player.y_map = y);
	(1) && (vars->player.x = x * X_IMG, vars->player.y = y * Y_IMG);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->player.img, x * X_IMG, y * Y_IMG);
}
