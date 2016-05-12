/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 02:32:28 by telain            #+#    #+#             */
/*   Updated: 2016/05/11 19:54:32 by telain           ###   ########.fr       */
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
	int			x1;
	int			x2;
	int			y1;
	int			y2;
}				t_env;

# include <fcntl.h>
# include <math.h>
# include "../includes/libft.h"
# include "mlx.h"
#include <stdio.h>

void	read_file(t_env *e);
void	line(t_env *e);
void	oct_1(t_env *e, int dx, int dy);
void	oct_2(t_env *e, int dx, int dy);
void	oct_3(t_env *e, int dx, int dy);
void	oct_4(t_env *e, int dx, int dy);
void	oct_5(t_env *e, int dx, int dy);
void	oct_6(t_env *e, int dx, int dy);
void	oct_7(t_env *e, int dx, int dy);
void	oct_8(t_env *e, int dx, int dy);
void	draw_grid(t_env *e);

#endif
