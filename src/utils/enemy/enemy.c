/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:29:00 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 23:38:49 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"
#include <stdlib.h>

static int	can_enemy_move(t_game *game, int new_x, int new_y)
{
	char	next_pos;

	if (new_x < 0 || new_x >= game->width || new_y < 0 || new_y >= game->height)
		return (0);
	next_pos = game->map[new_y][new_x];
	return (next_pos != '1' && next_pos != 'E' && next_pos != 'C');
}

static void	update_enemy_pos(t_game *game, int new_x, int new_y)
{
	game->map[game->enemy_pos.y][game->enemy_pos.x] = '0';
	game->map[new_y][new_x] = 'P';
	game->enemy_pos.x = new_x;
	game->enemy_pos.y = new_y;
}

static void	get_enemy_move(t_game *game, int *new_x, int *new_y)
{
	int	dx;
	int	dy;

	dx = game->player_pos.x - game->enemy_pos.x;
	dy = game->player_pos.y - game->enemy_pos.y;
	*new_x = game->enemy_pos.x;
	*new_y = game->enemy_pos.y;
	if (abs(dx) > abs(dy))
	{
		if (dx > 0)
			(*new_x)++;
		else
			(*new_x)--;
	}
	else
	{
		if (dy > 0)
			(*new_y)++;
		else
			(*new_y)--;
	}
}

void	move_enemy(t_game *game)
{
	int	new_x;
	int	new_y;

	get_enemy_move(game, &new_x, &new_y);
	if (can_enemy_move(game, new_x, new_y))
		update_enemy_pos(game, new_x, new_y);
}

int	check_enemy_collision(t_game *game)
{
	return (game->player_pos.x == game->enemy_pos.x
		&& game->player_pos.y == game->enemy_pos.y);
}
