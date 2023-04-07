/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:36:45 by truangsi          #+#    #+#             */
/*   Updated: 2023/04/07 12:09:08 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_split
{
	int		count;
	int		slot;
	size_t	i;
}	t_split;

void		double_free(char **arr);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);

#endif