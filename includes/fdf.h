/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 02:32:28 by telain            #+#    #+#             */
/*   Updated: 2016/03/25 15:03:42 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	char		*file;
	int			fd;
	int			**grid;
	int			lines;
	int			heigh;
	int			len;
	int			size_i;
	int			size_j;
	int			start[2];
}				t_env;

# include <fcntl.h>
# include <math.h>
# include "../includes/libft.h"
# include "mlx.h"
#include <stdio.h>

void	read_file(t_env *e);
void	line(int x1, int y1, int x2, int y2, t_env *e);
void	vert_line(int x1, int y1, int x2, int y2, t_env *e);
void	draw_grid(t_env *e);
void	print_grid(t_env *e);

#endif
