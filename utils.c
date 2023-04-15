/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:13:11 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/15 14:34:37 by truangsi         ###   ########.fr       */
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

int	click_exit(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win_ptr);
	free(fdf->node);
	exit (0);
}