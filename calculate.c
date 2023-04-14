/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:10:54 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/14 15:40:14 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cal_isometric(float *x, float *y, float z)
{
	//to keep the newest value after the cal so it they can be used to cal the next value
	float	prev_x;
	float	prev_y;

	// calcualte isometric formular
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(ANGLE);
	*y = (prev_x + prev_y) * sin(ANGLE) - z * DIMENSION;
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

float	cal_abs(float num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

float	find_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	cal_dda(t_fdf *fdf, float x1, float x2, float y1, float y2)
{
	float	dx;
	float	dy;
	float	max;
	// int	i = 0;

	dx = x2 - x1;
	dy = y2 - y1;
	max = find_max(cal_abs(dx), cal_abs(dy));
	dx /= max;
	dy /= max;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		my_mlx_pixel_put(fdf, (int)x1, (int)y1, fdf->node[fdf->i].color);
		x1 += dx;
		y1 += dy;
	}
}