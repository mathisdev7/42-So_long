/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:11:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/06 14:59:28 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"
#include "check_elements.h"

static void	update_positions(t_game *game, int i, int j)
{
	game->player_pos.x = j;
	game->player_pos.y = i;
}

static void	check_cell(t_game *game, int i, int j, int *counts)
{
	if (game->map[i][j] == 'P')
		counts[0]++;
	else if (game->map[i][j] == 'E')
		counts[1]++;
	else if (game->map[i][j] == 'C')
		game->collectibles++;
}

static void	count_elements(t_game *game, int *player_count, int *exit_count)
{
	int	i;
	int	j;
	int	counts[2];

	counts[0] = 0;
	counts[1] = 0;
	game->collectibles = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			check_cell(game, i, j, counts);
			if (game->map[i][j] == 'P')
				update_positions(game, i, j);
			j++;
		}
		i++;
	}
	*player_count = counts[0];
	*exit_count = counts[1];
}

int	check_elements(t_game *game)
{
	int	player_count;
	int	exit_count;

	count_elements(game, &player_count, &exit_count);
	if (player_count != 1)
	{
		ft_putstr_fd("Error\nMap must contain exactly one player (P)\n", 2);
		return (0);
	}
	if (exit_count != 1)
	{
		ft_putstr_fd("Error\nMap must contain exactly one exit (E)\n", 2);
		return (0);
	}
	if (game->collectibles < 1)
	{
		ft_putstr_fd("Error\nMap must contain at least one collectible (C)\n",
			2);
		return (0);
	}
	place_enemy(game);
	return (1);
}
