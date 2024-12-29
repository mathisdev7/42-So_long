/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:15:00 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 19:15:02 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_READER_H
# define MAP_READER_H

# include "../../main.h"

int		count_lines(char *map_path);
char	**read_map_file(char *map_path, int height);

#endif
