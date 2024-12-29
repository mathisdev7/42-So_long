/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:51:23 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 23:11:02 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

static char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
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

int	check_path(t_game *game)
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
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player_pos.x, game->player_pos.y, &collectibles);
	free_map(map_copy);
	return (collectibles == 0);
}
