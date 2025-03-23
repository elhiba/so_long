/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:59:19 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/06 02:54:05 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	player_up(int key, t_game *vars)
{
	if (vars->player.y - Y_IMG == 0 || map_visulizer(key, vars) == 0)
		return ;
	(1) && (vars->player.y -= Y_IMG, ++vars->player.move);
	ft_printf("You Moved:\t%i time!\a\n", vars->player.move);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->ground,
		vars->player.x, vars->player.y + Y_IMG);
}

void	player_down(int key, t_game *vars)
{
	if (vars->player.y + (Y_IMG * 2) == vars->y_window
		|| map_visulizer(key, vars) == 0)
		return ;
	(1) && (vars->player.y += Y_IMG, ++vars->player.move);
	ft_printf("You Moved:\t%i time!\a\n", vars->player.move);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->ground, vars->player.x, vars->player.y - Y_IMG);
}

void	player_left(int key, t_game *vars)
{
	if (vars->player.x - X_IMG == 0 || map_visulizer(key, vars) == 0)
		return ;
	(1) && (vars->player.x -= X_IMG, ++vars->player.move);
	ft_printf("You Moved:\t%i time!\a\n", vars->player.move);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->ground, vars->player.x + X_IMG, vars->player.y);
}

void	player_right(int key, t_game *vars)
{
	if (vars->player.x + (X_IMG * 2) == vars->x_window
		|| map_visulizer(key, vars) == 0)
		return ;
	(1) && (vars->player.x += X_IMG, ++vars->player.move);
	ft_printf("You Moved:\t%i time!\a\n", vars->player.move);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->ground, vars->player.x - X_IMG, vars->player.y);
}

int	file_failures(char **lines)
{
	player_fail(lines);
	ground_fail(lines);
	wall_fail(lines);
	collectible_fail(lines);
	exit_fail(lines);
	return (1);
}
