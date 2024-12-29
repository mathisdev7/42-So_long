/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:42:00 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 23:41:18 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <stdlib.h>

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->player_pos.x = -1;
	game->player_pos.y = -1;
	game->enemy_pos.x = -1;
	game->enemy_pos.y = -1;
	game->collectibles = 0;
	game->exit_found = 0;
	game->moves = 0;
	game->map_path = NULL;
}

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}
