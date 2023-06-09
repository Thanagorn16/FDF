/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:42:16 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/18 12:44:01 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920
# define RED 0x00FF0000
# define BLUE 0x00002E95
# define GREY 0x007E8C93
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define ANGLE 0.523599
# define TRANSLATE 20
# define DIMENSION 1

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "key.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_node
{
	float			x;
	float			y;
	float			z;
	long long		color;
}	t_node;

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
	int		dst_x;
	int		dst_y;
	char	*tmp;
	char	**line;
	t_node	*node;
}	t_fdf;

void	get_height(t_fdf *fdf, char **av);
void	get_width(t_fdf *fdf, char **av);
void	store_xyz(t_fdf *fdf, char **av);
void	cal_isometric(float *x, float *y, float z);
void	cal_center(t_fdf *fdf, int *width_point, int *height_point);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void	draw_lines(t_fdf *fdf);
void	cal_dda(t_fdf *fdf, t_node start, t_node end);
void	free_exit(t_fdf *fdf);
int		click_exit(t_fdf *fdf);
int		hook_events(int key, t_fdf *fdf);
int		double_arr_len(char **arr);
int		n_strlen(char *str);
int		htoi(char *hex);

#endif