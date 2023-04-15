#include "fdf.h"

void	erase_line(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			my_mlx_pixel_put(fdf, x++, y, BLACK);
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win_ptr, fdf->img, 0, 0);
}

void	translate_model(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->cells)
	{
		fdf->node[i].x += fdf->dst_x;
		fdf->node[i].y += fdf->dst_y;
		i++;
	}
	erase_line(fdf);
	draw_lines(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win_ptr, fdf->img, 0, 0);
	fdf->dst_x = 0;
	fdf->dst_y = 0;
}

int	hook_events(int key, t_fdf *fdf)
{
	int	translate;

	if (key == ESC)
		click_exit(fdf);
	translate = 0;
	if (key == KW || key == UP)
		fdf->dst_y -= TRANSLATE;
	else if (key == KS || key == DOWN)
		fdf->dst_y += TRANSLATE;
	else if (key == KA || key == LEFT)
		fdf->dst_x -= TRANSLATE;
	else if (key == KD || key == RIGHT)
		fdf->dst_x += TRANSLATE;
	else
		translate = 1;
	if (translate == 0)
		translate_model(fdf);
	return (0);
}