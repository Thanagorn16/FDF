/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:58 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/09 15:16:54 by truangsi         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	get_height(t_fdf *fdf, char **av)
{
	char	*tmp;
	int		fd;

	fd = open(av[1], O_RDONLY);
	fdf->height = 0;
	while (1) // count total line
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break;
		fdf->height++;
		free(tmp);
	}
	close(fd);
}

void	get_width(t_fdf *fdf, char **av)
{
	int		fd;
	int		loop_count;

	fd = open(av[1], O_RDONLY);
	loop_count = 0;
	fdf->width = 0;
	while (1)
	{
		fdf->tmp = get_next_line(fd);
		if (!fdf->tmp)
			break ;
		fdf->line = ft_split(fdf->tmp, ' ');
		fdf->i = 0;
		while (fdf->line[fdf->i])
		{
			if (loop_count == 0)
				fdf->width++;
			fdf->i++;
		}
		if (fdf->i > fdf->width || fdf->i < fdf->width) // error if i is greater or lesser than width
			exit (0);
		loop_count = 1;
	}
	close (fd);
}

void	store_xyz(t_fdf *fdf, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	fdf->cells = fdf->width * fdf->height;
	fdf->node = (t_node *)malloc(sizeof(t_node) * fdf->cells);
	fdf->j = 0;
	fdf->k = 0;
	while (fdf->j < fdf->cells)
	{
		fdf->tmp = get_next_line(fd);
		if (!fdf->tmp)
			break ;
		fdf->line = ft_split(fdf->tmp, ' ');
		fdf->i = 0;
		while (fdf->line[fdf->i])
		{
			fdf->node[fdf->j].z = (float)ft_atoi(fdf->line[fdf->i]);
			fdf->node[fdf->j].x = fdf->i * 10;
			fdf->node[fdf->j].y = fdf->k;
			// printf("x:%d   / y:%d\n", (int)fdf.node[j].x, (int)fdf.node[j].y);
			// printf("z:%d\n", (int) fdf.node[j].z);
			fdf->j++;
			fdf->i++;
		}
		fdf->k += 10;
	}
	close (fd);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	int		i;
	int		j;

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

	// put pixel
	i = 0;
	j = 0;
	while (i < fdf.cells)
	{
		my_mlx_pixel_put(&fdf, fdf.node[i].x, fdf.node[i].y, WHITE);
		i++;
	}

	mlx_put_image_to_window(fdf.mlx, fdf.win_ptr, fdf.img, 0, 0);

	// setup hooks
	mlx_hook(fdf.win_ptr, 2, 0, &handle_keypress, &fdf);

	mlx_loop(fdf.mlx);
}