/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:24:41 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 17:35:55 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <fcntl.h>

static void	put_image(void *mlx, void *win, char c, t_pos pos)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	if (c == 'P')
		path = "./assets/player.xpm";
	else if (c == '1')
		path = "./assets/wall.xpm";
	else if (c == 'C')
		path = "./assets/collectible.xpm";
	else if (c == 'E')
		path = "./assets/exit.xpm";
	else
		path = "./assets/floor.xpm";
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	if (!img)
		return ;
	mlx_put_image_to_window(mlx, win, img, pos.x * 32, pos.y * 32);
	mlx_destroy_image(mlx, img);
}

static int	count_lines(char *map_path)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	fill_map(char *map_path, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	game->height = count_lines(map_path);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return ;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return ;
	i = 0;
	while ((line = get_next_line(fd)))
	{
		game->map[i] = line;
		if (i == 0)
			game->width = ft_strlen(line) - 1;
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	render(game);
}

int	render(t_game *game)
{
	t_pos	pos;
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			pos.x = j;
			pos.y = i;
			put_image(game->mlx, game->win, '0', pos);
			if (game->map[i][j] != '0')
				put_image(game->mlx, game->win, game->map[i][j], pos);
			j++;
		}
		i++;
	}
	return (0);
}
