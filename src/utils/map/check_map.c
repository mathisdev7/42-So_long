/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:58:48 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 23:09:29 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/get_next_line/get_next_line.h"
#include "../../main.h"
#include "check_elements.h"
#include <fcntl.h>

static int	check_rectangular(char **map)
{
	int		i;
	size_t	len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (!game->map || !game->map[0])
	{
		ft_putstr_fd("Error\nEmpty map\n", 2);
		return (0);
	}
	if (!check_rectangular(game->map))
	{
		ft_putstr_fd("Error\nMap must be rectangular\n", 2);
		return (0);
	}
	if (!check_walls(game->map, game->height, game->width))
	{
		ft_putstr_fd("Error\nMap must be surrounded by walls\n", 2);
		return (0);
	}
	if (!check_elements(game))
		return (0);
	if (!check_path(game))
	{
		ft_putstr_fd("Error\nThe player can't reach the exit\n", 2);
		return (0);
	}
	return (1);
}
