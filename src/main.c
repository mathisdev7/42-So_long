/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:33:19 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 16:05:52 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minilibx-linux/mlx.h"
#include "main.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	char	*map_path;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
	map_path = argv[1];
	printf("%d\n", check_map(map_path));
	relative_path = "./assets/verstappen.xpm";
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 5);
	mlx_loop(mlx);
}
