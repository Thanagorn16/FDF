/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:58 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/12 15:15:26 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int key, t_fdf *fr)
{
	if (key == K_ESC)
	{
		mlx_destroy_window(fr->mlx, fr->win_ptr);
		exit (0);
	}
	return (0);
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	cal_isometric(float *x, float *y, float z)
{
	//to keep the newest value after the cal so it they can be used to cal the next value
	float	prev_x;
	float	prev_y;

	// calcualte isometric formular
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(ANGLE);
	*y = (prev_x + prev_y) * sin(ANGLE) - z;
}

void	cal_center(t_fdf *fdf, int *width_point, int *height_point)
{
	int	x_map;
	int	y_map;
	int	half_x_map;
	int	half_y_map;
	int	i;

	// get width and height of the map
	x_map = (fdf->width * fdf->x_map_dist) / 2;
	y_map = (fdf->height * fdf->x_map_dist) / 2; //get the height of the map
	// get center of the map
	half_x_map = (x_map - y_map) * cos(ANGLE);
	half_y_map = (x_map + y_map) * sin(ANGLE);
	// get starting point for window
	*width_point = (WINDOW_WIDTH / 2) - half_x_map; // get starting point for x on the window
	*height_point = (WINDOW_HEIGHT / 2) - half_y_map; // get starting point for y on the window
	// set center
	i = 0;
	while (i < fdf->cells)
	{
		cal_isometric(&fdf->node[i].x, &fdf->node[i].y, fdf->node[i].z);
		fdf->node[i].x += *width_point;
		fdf->node[i].y += *height_point;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	// int		i;
	// int		j;
	int		width_point;
	int		height_point;

	(void) ac;
	get_height(&fdf, av);
	get_width(&fdf, av);
	store_xyz(&fdf, av);
	// minilib
	fdf.mlx = mlx_init();
	if (!fdf.mlx)
		return (0);
	fdf.win_ptr = mlx_new_window(fdf.mlx,  1000, 1080, "fdf");
	if (!fdf.win_ptr)
		return (0);
	// create image
	fdf.img = mlx_new_image(fdf.mlx, 1000, 1080);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bits_per_pixel, &fdf.line_length, &fdf.endian);
	// cal_center & cal_isomatric
	cal_center(&fdf, &width_point, &height_point);
	// put pixel
	draw_points(&fdf);
	draw_lines(&fdf);

	mlx_put_image_to_window(fdf.mlx, fdf.win_ptr, fdf.img, 0, 0);

	// setup hooks
	mlx_hook(fdf.win_ptr, 2, 0, &handle_keypress, &fdf);

	mlx_loop(fdf.mlx);
}