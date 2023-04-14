#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_points(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->cells)
	{
		my_mlx_pixel_put(fdf, fdf->node[i].x, fdf->node[i].y, WHITE);
		i++;
	}
}

void	draw_lines(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->i = 0;
	while (i < fdf->cells)
	{
		if ((i + 1) % fdf->width != 0) //reaching width(edge) will result in 0
		{
			// draw horizontal lines
				cal_dda(fdf, fdf->node[i].x, fdf->node[i + 1].x,
					fdf->node[i].y, fdf->node[i + 1].y);
		}
		if (i < fdf->width * (fdf->height - 1))
		{
			// draw vertical lines
				cal_dda(fdf, fdf->node[i].x, fdf->node[i + (fdf->width)].x,
					fdf->node[i].y, fdf->node[i + (fdf->width)].y);
		}
		i++;
		fdf->i++; //colorize the line
	}
}