/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:58 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/15 14:35:47 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;
	int		width_point;
	int		height_point;

	if (ac != 2)
		return (0);
	get_height(&fdf, av);
	get_width(&fdf, av);
	store_xyz(&fdf, av);
	fdf.mlx = mlx_init();
	if (!fdf.mlx)
		return (0);
	fdf.win_ptr = mlx_new_window(fdf.mlx,  WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	if (!fdf.win_ptr)
		return (0);
	fdf.img = mlx_new_image(fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bits_per_pixel, &fdf.line_length, &fdf.endian);
	cal_center(&fdf, &width_point, &height_point);
	draw_lines(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win_ptr, fdf.img, 0, 0);
	mlx_hook(fdf.win_ptr, 2, 0, &hook_events, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, &click_exit, &fdf);
	mlx_loop(fdf.mlx);
}