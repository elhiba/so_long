/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:45:49 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/06 15:11:31 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	line_counter(char **lines)
{
	int	count;

	count = 0;
	while (lines[count])
		count++;
	return (count);
}

void	max_len(char *map, t_game *vars)
{
	char	*line;
	int		count;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd <= 0)
		exit(1);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	vars->line_len = count;
	line = NULL;
	close(fd);
}

int	autofree(char **lines, char *error)
{
	char	**tmp;

	if (!lines || !*lines)
	{
		if (lines)
			free(lines);
		exit(error_handler(error));
	}
	tmp = lines;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(lines);
	if (error)
		error_handler(error);
	exit(-1);
	return (1);
}

void	load_images(t_game *vars)
{
	vars->collectible_path = COLLECTIBLE;
	vars->collectible = mlx_xpm_file_to_image(vars->mlx,
			vars->collectible_path, &vars->img_width, &vars->img_height);
	vars->wall_path = WALL;
	vars->wall = mlx_xpm_file_to_image(vars->mlx, vars->wall_path,
			&vars->img_width, &vars->img_height);
	vars->ground_path = GROUND;
	vars->ground = mlx_xpm_file_to_image(vars->mlx, vars->ground_path,
			&vars->img_width, &vars->img_height);
	vars->exit_path = EXIT;
	vars->exit = mlx_xpm_file_to_image(vars->mlx, vars->exit_path,
			&vars->img_width, &vars->img_height);
}

int	error_handler(char *error_name)
{
	int	len;

	len = ft_strlen(error_name);
	if (ft_strnstr(error_name, "NO_INFILE", len))
		ft_putstr_fd("Error\n===\tMap missing! Adventure on hold.\n", 2);
	else if (ft_strnstr(error_name, "EXTENSION", len))
		ft_putstr_fd("Error\n===\t'.ber' extension needed!\n", 2);
	else if (ft_strnstr(error_name, "N_FOUND", len))
		ft_putstr_fd("Error\n===\tFile vanished!\n", 2);
	else if (ft_strnstr(error_name, "EMPTY", len))
		ft_putstr_fd("Error\n===\tFile is void!\n", 2);
	else if (ft_strnstr(error_name, "RECTANGLE", len))
		ft_putstr_fd("Error\n===\tMap must be rectangular!\n", 2);
	else if (ft_strnstr(error_name, "FLOOD", len))
		ft_putstr_fd("Error\n===\tThe hero can't reached all \
collectibles!\n", 2);
	else if (ft_strnstr(error_name, "NOT_MAP", len))
		ft_putstr_fd("Error\n===\tMap must be closed!\n", 2);
	else if (ft_strnstr(error_name, "P", len))
		ft_putstr_fd("Error\n===\tOnly one hero allowed!\n", 2);
	else if (ft_strnstr(error_name, "E", len))
		ft_putstr_fd("Error\n===\tSingle exit required!\n", 2);
	else if (ft_strnstr(error_name, "C", len))
		ft_putstr_fd("Error\n===\tTreasure missing!\n", 2);
	return (1);
}
