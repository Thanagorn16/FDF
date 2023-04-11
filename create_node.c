#include "fdf.h"

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
	fdf->x_map_dist = 30;
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
			fdf->node[fdf->j].x = fdf->i * fdf->x_map_dist;
			fdf->node[fdf->j].y = fdf->k * fdf->x_map_dist;
			// printf("x:%d   / y:%d\n", (int)fdf.node[j].x, (int)fdf.node[j].y);
			// printf("z:%d\n", (int) fdf.node[j].z);
			fdf->j++;
			fdf->i++;
		}
		// fdf->k += 10;
		fdf->k++;
	}
	// printf("k%d", fdf->k);
	close (fd);
}