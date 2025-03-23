/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:13:43 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/23 15:06:39 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "../includes/gnl/get_next_line.h"
# include "../includes/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

/*
 * Attention!, if you change image size X and Y you should change IMG_SIZE too 
 * IMG_SIZE in (NORMINNETE isn't allowed!)
 */
# define X_IMG 32
# define Y_IMG 32

# define IMG_SIZE "32"

# define PLAYER "./textures/" IMG_SIZE "/P.xpm"
# define WALL "./textures/" IMG_SIZE "/1.xpm"
# define EXIT "./textures/" IMG_SIZE "/E.xpm"
# define EXIT_OPEN "./textures/" IMG_SIZE "/EO.xpm"
# define GROUND "./textures/" IMG_SIZE "/0.xpm"
# define COLLECTIBLE "./textures/" IMG_SIZE "/C.xpm"

# define ESC 65307

# define UP 65362
# define UP_W 119

# define DOWN 65364
# define DOWN_S 115

# define LEFT 65361
# define LEFT_A 97

# define RIGHT 65363
# define RIGHT_D 100

typedef struct s_player
{
	void	*img;
	char	*img_path;
	int		x;
	int		y;
	int		x_map;
	int		y_map;
	int		p_width;
	int		p_height;
	int		move;
	int		collectible;
	int		collected;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;

	void		*ground;
	char		*ground_path;

	void		*wall;
	char		*wall_path;

	void		*collectible;
	char		*collectible_path;

	void		*exit;
	int			exit_x;
	int			exit_y;
	char		*exit_path;

	char		**map;
	int			x_map_len;
	int			y_map_len;
	int			img_width;
	int			img_height;
	int			x_window;
	int			y_window;
	int			line_len;
	t_player	player;

}				t_game;

/* Map checker */
void	max_len(char *map, t_game *vars);
int		map_visulizer(int key, t_game *vars);

/* Game */
void	gui(t_game *vars, char **map);
void	put_img(t_game **vars, char *file_name, int x, int y);
void	player_move(int key, t_game *vars);

/* Player moves */
void	player_up(int key, t_game *vars);
void	player_down(int key, t_game *vars);
void	player_left(int key, t_game *vars);
void	player_right(int key, t_game *vars);

/* Put items */

void	put_collectible(t_game *vars, int x, int y);
void	put_wall(t_game *vars, int x, int y);
void	put_ground(t_game *vars, int x, int y);
void	put_exit(t_game *vars, int x, int y);
void	put_player(t_game *vars, int x, int y);

/* Files failure */
void	wall_fail(char **lines);
void	exit_fail(char **lines);
void	ground_fail(char **lines);
void	collectible_fail(char **lines);
void	player_fail(char **lines);

/* handler */
int		file_failures(char **lines);
int		sus(t_game *vars);

/* close win */
int		close_window(t_game *vars);

/* Map stuff */
int		extension_map(char *extension);
char	**isvalid_map(char *map, t_game *vars);
void	valid_path(t_game *vars, char **lines);

/*  */
void	load_images(t_game *vars);
void	open_door(t_game *vars);

/* Utils */
int		line_counter(char **lines);
int		autofree(char **lines, char *error);
int		error_handler(char *error_name);
#endif
