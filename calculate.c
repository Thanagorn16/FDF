#include "fdf.h"

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