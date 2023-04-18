/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:11:48 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/18 12:42:56 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_lines(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->i = 0;
	while (i < fdf->cells)
	{
		if ((i + 1) % fdf->width != 0)
			cal_dda(fdf, fdf->node[i], fdf->node[i + 1]);
		if (i < fdf->width * (fdf->height - 1))
			cal_dda(fdf, fdf->node[i], fdf->node[i + (fdf->width)]);
		i++;
		fdf->i++;
	}
}
