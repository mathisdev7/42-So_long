/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:42:00 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/24 13:25:06 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static char	*get_image_path(char c, t_pos pos, t_game *game)
{
	if (c == 'P')
	{
		if (pos.x == game->enemy_pos.x && pos.y == game->enemy_pos.y)
			return ("./assets/enemy.xpm");
		return ("./assets/player.xpm");
	}
	else if (c == '1')
		return ("./assets/wall.xpm");
	else if (c == 'C')
		return ("./assets/collectible.xpm");
	else if (c == 'E')
		return ("./assets/exit.xpm");
	return ("./assets/floor.xpm");
}

static void	put_image(t_game *game, t_pos pos, char c)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	path = get_image_path(c, pos, game);
	img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	if (!img)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, img, pos.x * 32, pos.y * 32);
	mlx_destroy_image(game->mlx, img);
}

int	render(t_game *game)
{
	t_pos	pos;
	int		i;
	int		j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j] && game->map[i][j] != '\n')
		{
			pos.x = j;
			pos.y = i;
			put_image(game, pos, '0');
			if (game->map[i][j] != '0')
				put_image(game, pos, game->map[i][j]);
		}
	}
	return (0);
}
