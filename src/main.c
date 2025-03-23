/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:48:52 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/05 22:33:26 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char *av[])
{
	t_game	vars;
	char	**lines;
	int		map;

	if (ac != 2)
		return (autofree(NULL, "NO_INFILE"));
	map = extension_map(av[1]);
	if (!map)
		return (autofree(NULL, "EXTENSION"));
	ft_bzero(&vars, sizeof(t_game));
	max_len(av[1], &vars);
	lines = isvalid_map(av[1], &vars);
	gui(&vars, lines);
}
