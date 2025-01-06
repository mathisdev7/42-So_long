/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:30:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/06 14:55:21 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static int	check_distance_to_player(t_game *game, int x, int y)
{
	int	distance;

	distance = ((x - game->player_pos.x) * (x - game->player_pos.x)) + ((y
				- game->player_pos.y) * (y - game->player_pos.y));
	return (distance >= 9);
}

static int	check_distance_to_collectible(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	distance;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
			{
				distance = ((x - j) * (x - j)) + ((y - i) * (y - i));
				if (distance < 4)
					return (0);
			}
		}
	}
	return (1);
}

int	is_valid_enemy_position(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'E'
		|| game->map[y][x] == 'C' || game->map[y][x] == 'P')
		return (0);
	if (!check_distance_to_player(game, x, y))
		return (0);
	return (check_distance_to_collectible(game, x, y));
}
