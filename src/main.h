/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:41:10 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 16:07:58 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../include/libft/libft.h"
# include "../include/minilibx-linux/mlx.h"

int		check_map(char *map_path);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif
