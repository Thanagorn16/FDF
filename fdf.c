/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:58 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/14 16:59:55 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;
	int		width_point;
	int		height_point;

	(void) ac;
	// printf("0000000000\n");
	get_height(&fdf, av);
	// printf("out of height\n");
	get_width(&fdf, av);
	// printf("out of width\n");
	store_xyz(&fdf, av);
	// printf("11111111\n");
	// minilib
	fdf.mlx = mlx_init();
	if (!fdf.mlx)
		return (0);
	fdf.win_ptr = mlx_new_window(fdf.mlx,  WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	if (!fdf.win_ptr)
		return (0);
	// create image
	fdf.img = mlx_new_image(fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bits_per_pixel, &fdf.line_length, &fdf.endian);
	// cal_center & cal_isomatric
	// printf("2222222222222\n");
	cal_center(&fdf, &width_point, &height_point);
	// put pixel
	// draw_points(&fdf);
	draw_lines(&fdf);

	mlx_put_image_to_window(fdf.mlx, fdf.win_ptr, fdf.img, 0, 0);

	// setup hooks
	mlx_hook(fdf.win_ptr, 2, 0, &hook_events, &fdf);

	mlx_loop(fdf.mlx);
}