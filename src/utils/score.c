/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:05:00 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 23:05:00 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "score.h"
#include <fcntl.h>
#include <limits.h>

static char	*get_score_file_path(char *map_path)
{
	char	*score_file;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(map_path);
	score_file = malloc(len + 7);
	if (!score_file)
		return (NULL);
	i = 0;
	while (map_path[i] && map_path[i] != '.')
	{
		score_file[i] = map_path[i];
		i++;
	}
	j = 0;
	while (".score"[j])
		score_file[i++] = ".score"[j++];
	score_file[i] = '\0';
	return (score_file);
}

static int	read_high_score(char *score_file)
{
	int		fd;
	char	*line;
	int		score;

	fd = open(score_file, O_RDONLY);
	if (fd == -1)
		return (INT_MAX);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (INT_MAX);
	}
	score = ft_atoi(line);
	free(line);
	close(fd);
	return (score);
}

static void	write_high_score(char *score_file, int score)
{
	int		fd;
	char	*score_str;

	fd = open(score_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	score_str = ft_itoa(score);
	if (!score_str)
	{
		close(fd);
		return ;
	}
	ft_putstr_fd(score_str, fd);
	free(score_str);
	close(fd);
}

void	update_high_score(char *map_path, int moves)
{
	char	*score_file;
	int		high_score;

	score_file = get_score_file_path(map_path);
	if (!score_file)
		return ;
	high_score = read_high_score(score_file);
	if (moves < high_score)
	{
		write_high_score(score_file, moves);
		ft_putstr_fd("New high score! ", 1);
		ft_putnbr_fd(moves, 1);
		ft_putstr_fd(" moves\n", 1);
	}
	else if (high_score != INT_MAX)
	{
		ft_putstr_fd("High score: ", 1);
		ft_putnbr_fd(high_score, 1);
		ft_putstr_fd(" moves\n", 1);
	}
	free(score_file);
}
