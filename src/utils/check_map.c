/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:58:48 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 18:20:19 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line/get_next_line.h"
#include "../main.h"
#include <fcntl.h>

static int	check_rectangular(char **map)
{
	int	i;
	int	len;

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

static void	flood_fill(char **map, int x, int y, int *collectibles)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		(*collectibles)--;
	if (map[y][x] == 'E')
		map[y][x] = 'F';
	else
		map[y][x] = 'F';
	flood_fill(map, x + 1, y, collectibles);
	flood_fill(map, x - 1, y, collectibles);
	flood_fill(map, x, y + 1, collectibles);
	flood_fill(map, x, y - 1, collectibles);
}

static int	check_path(t_game *game)
{
	int		collectibles;
	int		i;
	int		j;
	char	**map_copy;

	collectibles = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (game->map[i][j] == 'C')
				collectibles++;
	}
	map_copy = ft_split(game->map, '\n');
	flood_fill(map_copy, game->player_pos.x, game->player_pos.y, &collectibles);
	i = -1;
	while (map_copy[++i])
		free(map_copy[i]);
	free(map_copy);
	return (collectibles == 0);
}

int	check_map(char *map_path, t_game *game)
{
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
	if (!check_path(game))
	{
		ft_putstr_fd("Error\nNo valid path found\n", 2);
		return (0);
	}
	return (1);
}
