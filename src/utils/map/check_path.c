/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:51:23 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/06 15:01:41 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"
#include "../handlers.h"
#include "map_utils.h"

void	flood_fill(char **map, int x, int y, int *total_to_reach)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E')
		(*total_to_reach)--;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, total_to_reach);
	flood_fill(map, x - 1, y, total_to_reach);
	flood_fill(map, x, y + 1, total_to_reach);
	flood_fill(map, x, y - 1, total_to_reach);
}

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
		{
			if (game->map[i][j] == 'C' || game->map[i][j] == 'E')
				count++;
		}
	}
	return (count);
}

int	check_path(t_game *game)
{
	char	**map_copy;
	int		total_to_reach;
	int		result;

	total_to_reach = count_objectives(game);
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player_pos.x, game->player_pos.y,
		&total_to_reach);
	result = (total_to_reach == 0);
	free_char_map(map_copy);
	return (result);
}
