/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:33:19 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 18:20:19 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minilibx-linux/mlx.h"
#include "main.h"
#include <stdlib.h>

int	expose_handler(t_game *game)
{
	render(game);
	return (0);
}

static void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->player_pos.x = -1;
	game->player_pos.y = -1;
	game->collectibles = 0;
	game->exit_found = 0;
}

static int	get_map_dimensions(char *map_path, t_game *game)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	game->width = ft_strlen(line) - 1;
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	game->height = height;
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long map_path\n", 2);
		return (1);
	}
	init_game(&game);
	if (!get_map_dimensions(argv[1], &game))
	{
		ft_putstr_fd("Error\nFailed to read map\n", 2);
		return (1);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 32, game.height * 32,
			"So Long");
	fill_map(argv[1], &game);
	if (!check_map(argv[1], &game))
		return (1);
	mlx_expose_hook(game.win, expose_handler, &game);
	mlx_loop(game.mlx);
	return (0);
}
