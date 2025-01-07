/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:13:27 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/07 11:07:05 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

static int	can_move(t_game *game, int new_x, int new_y)
{
	char	next_pos;

	next_pos = game->map[new_y][new_x];
	if (next_pos == '1')
		return (0);
	if (next_pos == 'C')
		game->collectibles--;
	if (next_pos == 'E')
	{
		if (game->collectibles == 0)
			return (2);
		return (0);
	}
	return (1);
}

static void	update_player_pos(t_game *game, int new_x, int new_y)
{
	game->map[game->player_pos.y][game->player_pos.x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_pos.x = new_x;
	game->player_pos.y = new_y;
	render(game);
}

int	move_player(t_game *game, int key)
{
	int	new_x;
	int	new_y;
	int	move_status;

	new_x = game->player_pos.x;
	new_y = game->player_pos.y;
	if (key == 119)
		new_y--;
	else if (key == 115)
		new_y++;
	else if (key == 97)
		new_x--;
	else if (key == 100)
		new_x++;
	else
		return (0);
	move_status = can_move(game, new_x, new_y);
	if (move_status)
	{
		update_player_pos(game, new_x, new_y);
		return (move_status);
	}
	return (0);
}
