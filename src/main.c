/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:33:19 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/06 15:25:55 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minilibx-linux/mlx.h"
#include "main.h"
#include "utils/handlers.h"
#include <stdlib.h>

static int	setup_game(t_game *game, char *map_path)
{
	game->map_path = ft_strdup(map_path);
	if (!game->map_path)
		return (0);
	fill_map(map_path, game);
	if (!check_map(game))
	{
		free_map(game);
		free(game->map_path);
		return (0);
	}
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32,
			"so_long");
	render(game);
	mlx_key_hook(game->win, key_handler, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_expose_hook(game->win, expose_handler, game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long [map_path]\n", 2);
		return (1);
	}
	init_game(&game);
	if (!setup_game(&game, argv[1]))
		return (1);
	mlx_loop(game.mlx);
	close_window(&game);
	return (0);
}
