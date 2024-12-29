/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:52:00 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 22:56:09 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "../main.h"
# include "../../include/libft/libft.h"

void	free_map(t_game *game);
int		expose_handler(t_game *game);
int		key_handler(int keycode, t_game *game);
int		close_window(t_game *game);
void	init_game(t_game *game);

#endif
