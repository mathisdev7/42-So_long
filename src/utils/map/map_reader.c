/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:30:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/06 14:59:15 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

static char	**allocate_map(int height)
{
	char	**map;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	return (map);
}

static void	free_allocated_lines(char **map, int i)
{
	while (--i >= 0)
		free(map[i]);
	free(map);
}

static int	open_map_file(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

static int	read_map_lines(char **map, int fd, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			free_allocated_lines(map, i);
			return (0);
		}
		i++;
	}
	map[i] = NULL;
	return (1);
}

char	**read_map_file(char *map_path, int height)
{
	char	**map;
	int		fd;

	map = allocate_map(height);
	if (!map)
		return (NULL);
	fd = open_map_file(map_path);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	if (!read_map_lines(map, fd, height))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}
