/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:41:10 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/06 15:10:48 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../include/get_next_line/get_next_line.h"
# include "../include/libft/libft.h"
# include "../include/minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		height;
	int		width;
	t_pos	player_pos;
	t_pos	enemy_pos;
	int		collectibles;
	int		exit_found;
	int		moves;
	char	*map_path;
}			t_game;

int			check_map(t_game *game);
int			check_path(t_game *game);
void		fill_map(char *map_path, t_game *game);
int			render(t_game *game);
int			move_player(t_game *game, int key);
char		**ft_split(char const *s, char c);
void		place_enemy(t_game *game);
void		flood_fill(char **map, int x, int y, int *collectibles);
char		*get_next_line(int fd);
#endif
