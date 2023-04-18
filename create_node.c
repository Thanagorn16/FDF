/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:09:15 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/18 12:10:05 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_height(t_fdf *fdf, char **av)
{
	char	*tmp;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(0);
	fdf->height = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		fdf->height++;
		free(tmp);
	}
	close(fd);
}

void	process_width(t_fdf *fdf)
{
	int		loop_count;

	loop_count = 0;
	fdf->width = 0;
	while (1)
	{
		fdf->tmp = get_next_line(fdf->fd);
		if (!fdf->tmp)
			break ;
		fdf->line = ft_split(fdf->tmp, ' ');
		if (!fdf->line)
			free_exit(fdf);
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
}

void	get_width(t_fdf *fdf, char **av)
{
	fdf->fd = open(av[1], O_RDONLY);
	if (fdf->fd < 0)
		exit(0);
	process_width(fdf);
	close (fdf->fd);
}

void	save_to_node(t_fdf *fdf)
{
	char	**arr;

	fdf->i = 0;
	while (fdf->line[fdf->i])
	{
		arr = ft_split(fdf->line[fdf->i], ',');
		if (!arr)
			free_exit(fdf);
		fdf->node[fdf->j].z = (float)ft_atoi(arr[0]);
		if (double_arr_len(arr) > 1)
			fdf->node[fdf->j].color = htoi(arr[1] + 2);
		else
			fdf->node[fdf->j].color = 16777215;
		fdf->node[fdf->j].x = fdf->i * fdf->x_map_dist;
		fdf->node[fdf->j].y = fdf->k * fdf->x_map_dist;
		double_free(arr);
		fdf->j++;
		fdf->i++;
	}
	fdf->k++;
}

void	store_xyz(t_fdf *fdf, char **av)
{
	fdf->fd = open(av[1], O_RDONLY);
	if (fdf->fd < 0)
		exit(0);
	fdf->cells = fdf->width * fdf->height;
	fdf->node = (t_node *)malloc(sizeof(t_node) * fdf->cells);
	if (!fdf->node)
		exit(0);
	fdf->j = 0;
	fdf->k = 0;
	fdf->x_map_dist = 30;
	while (fdf->j < fdf->cells)
	{
		fdf->tmp = get_next_line(fdf->fd);
		if (!fdf->tmp)
			exit(0);
		fdf->line = ft_split(fdf->tmp, ' ');
		if (!fdf->line)
			free_exit(fdf);
		save_to_node(fdf);
		free(fdf->tmp);
		double_free(fdf->line);
	}
	close (fdf->fd);
}
