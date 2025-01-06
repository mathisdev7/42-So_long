/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:30:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/06 14:56:24 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static int	calculate_distance(int x1, int y1, int x2, int y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

static void	update_enemy_position(t_game *game, int x, int y, int *max_distance)
{
	int	current_distance;

	current_distance = calculate_distance(x, y, game->player_pos.x,
			game->player_pos.y);
	if (current_distance > *max_distance)
	{
		*max_distance = current_distance;
		game->enemy_pos.x = x;
		game->enemy_pos.y = y;
	}
}

static void	set_default_position(t_game *game)
{
	game->enemy_pos.x = game->width - 2;
	game->enemy_pos.y = 1;
}

void	place_enemy(t_game *game)
{
	int	x;
	int	y;
	int	max_distance;

	max_distance = 0;
	set_default_position(game);
	y = 1;
	while (y < game->height - 1)
	{
		x = 1;
		while (x < game->width - 1)
		{
			if (is_valid_enemy_position(game, x, y)
				&& check_path_with_enemy(game, x, y))
				update_enemy_position(game, x, y, &max_distance);
			x++;
		}
		y++;
	}
}
