/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:34:31 by moel-hib          #+#    #+#             */
/*   Updated: 2025/02/19 15:08:30 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	exit_fail(char **lines)
{
	if (-1 == open(EXIT, O_RDONLY))
	{
		ft_putstr_fd("Error\n===\tWhoa, EXIT not found! \
Your escape plan just ghosted you!\n", 2);
		autofree(lines, NULL);
	}
}

void	wall_fail(char **lines)
{
	if (-1 == open(WALL, O_RDONLY))
	{
		ft_putstr_fd("Error\n===\tNo wall detected! \
Did you build your home with invisible bricks?\n", 2);
		autofree(lines, NULL);
	}
}

void	ground_fail(char **lines)
{
	if (-1 == open(GROUND, O_RDONLY))
	{
		ft_putstr_fd("Error\n===\tGround MIA! Looks like \
we’re defying gravity, bro!\n", 2);
		autofree(lines, NULL);
	}
}

void	collectible_fail(char **lines)
{
	if (-1 == open(COLLECTIBLE, O_RDONLY))
	{
		ft_putstr_fd("Error\n===\tCollectibles missing! \
Even your loot is on vacation!\n", 2);
		autofree(lines, NULL);
	}
}

void	player_fail(char **lines)
{
	if (-1 == open(PLAYER, O_RDONLY))
	{
		ft_putstr_fd("Error\n===\tPlayer image not loaded! \
Did your avatar decide to stay home?\n", 2);
		autofree(lines, NULL);
	}
}
