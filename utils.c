/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:13:11 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/14 15:44:13 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	double_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	n_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	htoi(char *hex)
{
	long long	decimal;
	long long	base;
	int			i;
	int			length;

	length = n_strlen(hex);
	i = length - 1;
	base = 1;
	decimal = 0;
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			decimal += (hex[i] - 48) * base;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			decimal += (hex[i] - 55) * base;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			decimal += (hex[i] - 87) * base;
		base *= 16;
		i--;
	}
	return (decimal);
}
// void	store_xyz(t_fdf *fdf, char **av)
// {
// 	int	fd;
// 	char	**arr;
// 	// int	dec;

// 	fd = open(av[1], O_RDONLY);
// 	fdf->cells = fdf->width * fdf->height;
// 	fdf->node = (t_node *)malloc(sizeof(t_node) * fdf->cells);
// 	if (!fdf->node)
// 		exit(0);
// 	fdf->j = 0;
// 	fdf->k = 0;
// 	fdf->x_map_dist = 30;
// 	while (fdf->j < fdf->cells)
// 	{
// 		fdf->tmp = get_next_line(fd);
// 		if (!fdf->tmp)
// 			exit(0);
// 		fdf->line = ft_split(fdf->tmp, ' ');
// 		if (!fdf->line)
// 		{
// 			free(fdf->node);
// 			free(fdf->tmp);
// 		}
// 		fdf->i = 0;
// 		while (fdf->line[fdf->i])
// 		{
// 			arr = ft_split(fdf->line[fdf->i], ',');
// 			if (!arr)
// 			{
// 				free(fdf->node);
// 				free(fdf->tmp);
// 			}
// 			fdf->node[fdf->j].z = (float)ft_atoi(arr[0]); //store map
// 			if (double_arr_len(arr) > 1) //if color exists
// 			{
// 				// fdf->node[fdf->j].z = (float)ft_atoi(arr[0]); //store map
// 				// printf("arr:%s\n", arr[1]);
// 				fdf->node[fdf->j].color = htoi(arr[1] + 2); //stor color
// 			}
// 			else
// 			{
// 				// fdf->node[fdf->j].z = (float)ft_atoi(arr[0]);
// 				fdf->node[fdf->j].color = 16777215; //store white
// 			}

// 			// fdf->node[fdf->j].z = (float)ft_atoi(fdf->line[fdf->i]); // keep the actual value after split and atoi
// 			fdf->node[fdf->j].x = fdf->i * fdf->x_map_dist;
// 			fdf->node[fdf->j].y = fdf->k * fdf->x_map_dist;
// 			double_free(arr);
// 			// printf("x:%d   / y:%d\n", (int)fdf->node[fdf->j].x, (int)fdf->node[fdf->j].y);
// 			// printf("i:%d\n", fdf->i);
// 			// printf("z:%d\n", (int) fdf->node[fdf->j].z);
// 			// printf("color:%lld\n", fdf->node[fdf->j].color);
// 			// printf("---------------\n");
// 			fdf->j++;
// 			fdf->i++;
// 		}
// 		free(fdf->tmp);
// 		double_free(fdf->line);
// 		fdf->k++;
// 	}
// 	// printf("k%d", fdf->k);
// 	// exit(0);
// 	close (fd);
// }