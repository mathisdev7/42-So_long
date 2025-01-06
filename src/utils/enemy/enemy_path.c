/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:30:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/06 15:07:12 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map/map_utils.h"
#include "enemy.h"

static int	count_objectives(t_game *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (game->map[i][j] == 'C' || game->map[i][j] == 'E')
				count++;
	}
	return (count);
}

int	check_path_with_enemy(t_game *game, int x, int y)
{
	char	**test_map;
	int		total_to_reach;
	int		result;

	test_map = copy_map_with_enemy(game, x, y);
	if (!test_map)
		return (0);
	total_to_reach = count_objectives(game);
	flood_fill(test_map, game->player_pos.x, game->player_pos.y,
		&total_to_reach);
	result = (total_to_reach == 0);
	free_char_map(test_map);
	return (result);
}
