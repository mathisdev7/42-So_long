/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:15:00 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 21:12:30 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_reader.h"
#include <fcntl.h>

int	count_lines(char *map_path)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_map_file(char *map_path, int height)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
