#include "fdf.h"

int	render_rect(t_frac *fr, t_rect rect, int color)
{
	int	i;
	int j;

	if (!fr->win_ptr)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
			while (j < rect.x + rect.width)
				my_mlx_pixel_put(fr, j++, i, color);
			++i;
	}
	return (0);
}

void	render_background(t_frac *fr, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			my_mlx_pixel_put(fr, j++, i, color);
		i++;
	}
}

void	render(t_frac *fr)
{
	render_background(fr, GREY);
	render_rect(fr, (t_rect) {WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100}, RED);
	render_rect(fr, (t_rect) {0, 0, 100, 100}, BLUE);
	mlx_put_image_to_window(fr->mlx, fr->win_ptr, fr->img, 0, 0);
}