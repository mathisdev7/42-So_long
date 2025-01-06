/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:30:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/06 14:55:29 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static char	**allocate_map_copy(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (NULL);
	i = -1;
	while (++i < game->height)
	{
		map_copy[i] = malloc(sizeof(char) * (game->width + 1));
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
	}
	return (map_copy);
}

char	**copy_map_with_enemy(t_game *game, int x, int y)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = allocate_map_copy(game);
	if (!map_copy)
		return (NULL);
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			map_copy[i][j] = game->map[i][j];
		map_copy[i][j] = '\0';
	}
	map_copy[y][x] = '1';
	map_copy[game->height] = NULL;
	return (map_copy);
}
