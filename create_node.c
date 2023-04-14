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
	// int			value;

	length = n_strlen(hex);
	i = length - 1;
	base = 1;
	decimal = 0;
	while (i >= 0)
	{
		// printf("hey\n");
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 87) * base;
			base *= 16;
		}
		i--;
	}
	// printf("dec:%lld\n", decimal);
	return (decimal);
}

void	store_xyz(t_fdf *fdf, char **av)
{
	int	fd;
	char	**arr;
	// int	dec;

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
			arr = ft_split(fdf->line[fdf->i], ',');
			if (double_arr_len(arr) > 1) //if color exists
			{
				fdf->node[fdf->j].z = (float)ft_atoi(arr[0]); //store map
				// printf("arr:%s\n", arr[1]);
				fdf->node[fdf->j].color = htoi(arr[1] + 2); //stor color
			}
			else
			{
				fdf->node[fdf->j].z = (float)ft_atoi(arr[0]);
				fdf->node[fdf->j].color = 16777215; //store white
			}

			// fdf->node[fdf->j].z = (float)ft_atoi(fdf->line[fdf->i]); // keep the actual value after split and atoi
			fdf->node[fdf->j].x = fdf->i * fdf->x_map_dist;
			fdf->node[fdf->j].y = fdf->k * fdf->x_map_dist;
			// printf("x:%d   / y:%d\n", (int)fdf->node[fdf->j].x, (int)fdf->node[fdf->j].y);
			// printf("i:%d\n", fdf->i);
			// printf("z:%d\n", (int) fdf->node[fdf->j].z);
			// printf("color:%lld\n", fdf->node[fdf->j].color);
			// printf("---------------\n");
			fdf->j++;
			fdf->i++;
		}
		fdf->k++;
	}
	// printf("k%d", fdf->k);
	// exit(0);
	close (fd);
}