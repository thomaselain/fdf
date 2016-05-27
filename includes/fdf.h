/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 02:32:28 by telain            #+#    #+#             */
/*   Updated: 2016/05/27 18:21:56 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "../includes/libft.h"
# include "mlx.h"
# define I i * e->size_i
# define J j * e->size_j
# define IN (i + 1) * e->size_i
# define JN (j + 1) * e->size_j
# define WIN_X 1000
# define WIN_Y 600

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

/*
** main.c
*/
void			clear(t_env *e);
int				draw(int keycode, void *e);
void			new_env(t_env *e);

/*
** print_grid.c
*/
void			print_grid(t_env *e);

/*
** line.c
*/
void			line(t_env *e, int color);

/*
** read_file.c
*/
void			check_file_type(t_env *e);
int				get_lengh(char *line);
void			create_grid(t_env *e, char *line, int n);
void			read_file(t_env *e);

/*
** input.c
*/
int				find_key(int keycode, t_env *e);
void			move(int key, t_env *e);

/*
** oct_1-8.c
*/
void			oct_1(t_env *e, int dx, int dy);
void			oct_2(t_env *e, int dx, int dy);
void			oct_3(t_env *e, int dx, int dy);
void			oct_4(t_env *e, int dx, int dy);
void			oct_5(t_env *e, int dx, int dy);
void			oct_6(t_env *e, int dx, int dy);
void			oct_7(t_env *e, int dx, int dy);
void			oct_8(t_env *e, int dx, int dy);

/*
** draw_grid.c
*/
int				choose_color(int h);
void			write_opt(t_env *e);
void			draw_grid(t_env *e);

#endif
