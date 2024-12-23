/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:41:10 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 18:22:00 by mazeghou         ###   ########.fr       */
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
	int		collectibles;
	int		exit_found;
}			t_game;

int			check_map(char *map_path, t_game *game);
void		fill_map(char *map_path, t_game *game);
int			render(t_game *game);
char		**ft_split(char const *s, char c);

#endif
