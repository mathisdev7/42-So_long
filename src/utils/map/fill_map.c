/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:24:41 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/27 04:22:03 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"
#include "map_reader.h"
#include <fcntl.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static int	check_ber_extension(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || ft_strcmp(dot, ".ber") != 0)
	{
		ft_putstr_fd("Error\nMap file must have .ber extension\n", 2);
		return (0);
	}
	return (1);
}

static void	update_positions(t_game *game, int i, int j, int *found_player)
{
	if (!(*found_player))
	{
		game->player_pos.x = j;
		game->player_pos.y = i;
		*found_player = 1;
	}
	else
	{
		game->enemy_pos.x = j;
		game->enemy_pos.y = i;
	}
}

static void	init_map_data(t_game *game)
{
	int	i;
	int	j;
	int	found_player;

	game->collectibles = 0;
	game->exit_found = 0;
	found_player = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				update_positions(game, i, j, &found_player);
			else if (game->map[i][j] == 'C')
				game->collectibles++;
			else if (game->map[i][j] == 'E')
				game->exit_found = 1;
		}
	}
}

void	fill_map(char *map_path, t_game *game)
{
	if (!check_ber_extension(map_path))
		return ;
	game->height = count_lines(map_path);
	if (game->height <= 0)
		return ;
	game->map = read_map_file(map_path, game->height);
	if (!game->map)
		return ;
	if (game->map[0])
		game->width = ft_strlen(game->map[0]) - 1;
	init_map_data(game);
}
