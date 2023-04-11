/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:42:16 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/11 16:22:01 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1000
#define RED 0x00FF0000
#define BLUE 0x00002E95
#define GREY 0x007E8C93
#define WHITE 0x00FFFFFF
#define ANGLE 0.523599


#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>
#include <math.h>
#include "key.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct s_node
{
	float	x;
	float	y;
	float	z;
} t_node;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	// int		color;
} t_rect;

typedef struct s_fdf
{
	void	*mlx;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		fd;
	int		i;
	int		j;
	int		k;
	int		width;
	int		height;
	int		cells;
	int		x_map_dist;
	int		y_map_dist;
	char	*tmp;
	char	**line;
	t_node	*node;
} t_fdf;

void	get_height(t_fdf *fdf, char **av);
void	get_width(t_fdf *fdf, char **av);
void	store_xyz(t_fdf *fdf, char **av);
void	render_points(t_fdf *fdf);
void	render_line(t_fdf *fdf);

#endif