/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:30:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/06 15:17:25 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"
#include "map_utils.h"

void	free_char_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char	**init_map_copy(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (NULL);
	i = -1;
	while (++i < game->height)
	{
		map_copy[i] = malloc(sizeof(char) * (game->width + 1));
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
	}
	return (map_copy);
}

char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = init_map_copy(game);
	if (!map_copy)
		return (NULL);
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			map_copy[i][j] = game->map[i][j];
		map_copy[i][j] = '\0';
	}
	map_copy[game->height] = NULL;
	return (map_copy);
}

int	count_lines(char *file_path)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}
