#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	render_points(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->cells)
	{
		my_mlx_pixel_put(fdf, fdf->node[i].x, fdf->node[i].y, WHITE);
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
	// t_fdf	fdf;

	dx = x2 - x1;
	dy = y2 - y1;
	max = find_max(cal_abs(dx), cal_abs(dy));
	dx /= max;
	dy /= max;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		my_mlx_pixel_put(fdf->img, (int)x1, (int)y1, WHITE);
		x1 += dx;
		y1 += dy;
	}
}
void	render_line(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->cells)
	{
		// if (i + 1 != fdf->cells)
		// {
		// 	cal_dda(fdf->node[i].x, fdf->node[i + 1].x,
		// 			fdf->node[i].y, fdf->node[i + 1].y);
		// }
		cal_dda(fdf, fdf->node[i].x, fdf->node[i + 1].x,
				fdf->node[i].y, fdf->node[i + 1].y);
		// printf("x:%d   / y:%d\n", (int)fdf->node[i].x, (int)fdf->node[i].y);
		// printf("x2:%d   / y2:%d\n", (int)fdf->node[i + 1].x, (int)fdf->node[i + 1].y);
		i++;
	}
}