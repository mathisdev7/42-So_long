/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:52:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/07 11:01:43 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include "render.h"
#include <stdlib.h>

static void	handle_win(t_game *game)
{
	ft_putstr_fd("You won!\n", 1);
	mlx_loop_end(game->mlx);
}

static void	handle_move(t_game *game, int moved)
{
	game->moves++;
	ft_putstr_fd("Number of moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
	render(game);
	if (moved == 2)
		handle_win(game);
}

int	key_handler(int keycode, t_game *game)
{
	int	moved;

	if (keycode == 65307)
	{
		mlx_loop_end(game->mlx);
		return (0);
	}
	moved = move_player(game, keycode);
	if (moved)
		handle_move(game, moved);
	return (moved);
}

int	expose_handler(t_game *game)
{
	render(game);
	return (0);
}
