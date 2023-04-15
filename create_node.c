#include "fdf.h"

void	get_height(t_fdf *fdf, char **av)
{
	char	*tmp;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(0);
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
	if (fd < 0)
		exit(0);
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
		double_free(fdf->line);
		free(fdf->tmp);
		loop_count = 1;
	}
	close (fd);
}

void	save_to_node(t_fdf *fdf)
{
	char	**arr;

	fdf->i = 0;
	while (fdf->line[fdf->i])
	{
		arr = ft_split(fdf->line[fdf->i], ',');
		if (!arr)
		{
			free(fdf->node);
			free(fdf->tmp);
		}
		fdf->node[fdf->j].z = (float)ft_atoi(arr[0]); //store map
		if (double_arr_len(arr) > 1) //if color exists
			fdf->node[fdf->j].color = htoi(arr[1] + 2); //stor color
		else
			fdf->node[fdf->j].color = 16777215; //store white
		fdf->node[fdf->j].x = fdf->i * fdf->x_map_dist;
		fdf->node[fdf->j].y = fdf->k * fdf->x_map_dist;
		double_free(arr);
		fdf->j++;
		fdf->i++;
	}
}

void	store_xyz(t_fdf *fdf, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	fdf->cells = fdf->width * fdf->height;
	fdf->node = (t_node *)malloc(sizeof(t_node) * fdf->cells);
	if (!fdf->node)
		exit(0);
	fdf->j = 0;
	fdf->k = 0;
	fdf->x_map_dist = 30;
	while (fdf->j < fdf->cells)
	{
		fdf->tmp = get_next_line(fd);
		if (!fdf->tmp)
			exit(0);
		fdf->line = ft_split(fdf->tmp, ' ');
		if (!fdf->line)
		{
			free(fdf->node);
			free(fdf->tmp);
		}
		save_to_node(fdf);
		free(fdf->tmp);
		double_free(fdf->line);
		fdf->k++;
	}
	close (fd);
}