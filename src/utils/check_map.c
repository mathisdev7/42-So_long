/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:58:48 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 16:18:03 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line/get_next_line.h"
#include "../main.h"

static int	check_line_ones(char *line, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && line[i] == '1')
		i++;
	return (i == len);
}

static int	check_middle_lines(int fd, size_t len)
{
	char	*line;

	while ((line = get_next_line(fd)))
	{
		if (ft_strlen(line) - 1 != len || line[0] != '1' || line[len
			- 1] != '1')
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

int	check_map(char *map_path)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	len = ft_strlen(line) - 1;
	if (!check_line_ones(line, len))
		return (0);
	free(line);
	if (!check_middle_lines(fd, len))
		return (0);
	close(fd);
	return (1);
}
