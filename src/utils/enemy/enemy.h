/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:30:00 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/06 15:07:08 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include "../../main.h"
# include "../map/map_utils.h"

void	place_enemy(t_game *game);
int		is_valid_enemy_position(t_game *game, int x, int y);
char	**copy_map_with_enemy(t_game *game, int x, int y);
int		check_path_with_enemy(t_game *game, int x, int y);
void	move_enemy(t_game *game);
int		check_enemy_collision(t_game *game);

#endif
