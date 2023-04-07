/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:42:16 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/07 20:21:37 by truangsi         ###   ########.fr       */
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


#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>
#include "key.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	// int		color;
} t_rect;

typedef struct s_frac
{
	void	*mlx;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_frac;


#endif