/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:03:43 by telain            #+#    #+#             */
/*   Updated: 2016/06/03 14:12:24 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	hori_line(t_env *e, int i, int j)
{
	e->x1 = (I - J) + e->start[0];
	e->y1 = (I + J) / 3 + e->start[1]
		- e->grid[i][j] * e->height / 3;
	e->x2 = (I - JN) + e->start[0];
	e->y2 = (I + JN) / 3 + e->start[1]
		- e->grid[i][j + 1] * e->height / 3;
	line(e, choose_color(e->grid[i][j]));
}

void	vert_line(t_env *e, int i, int j)
{
	e->x1 = (I - J) + e->start[0];
	e->y1 = (I + J) / 3 + e->start[1]
		- e->grid[i][j] * e->height / 3;
	e->x2 = (IN - J) + e->start[0];
	e->y2 = (IN + J) / 3 + e->start[1]
		- e->grid[i + 1][j] * e->height / 3;
	line(e, choose_color(e->grid[i][j]));
}

void	init_opt(t_env *e)
{
	e->size_i = WIN_X / (e->len * 1.5);
	e->size_j = -e->size_i;
	e->height = 1;
	e->start[0] = -e->len + e->size_i * 2;
	e->start[1] = 400;
}

int		choose_color(int h)
{
	int		color;

	if (h <= -20)
		color = 0x03224c;
	else if (h < 1)
		color = 0x0131b4;
	else if (h <= 2)
		color = 0xf6dc12;
	else if (h <= 20)
		color = 0x3a9d23;
	else if (h <= 40)
		color = 0x88421d;
	else
		color = 0xffffff;
	return (color);
}

void	draw_grid(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	mlx_string_put(e->mlx, e->win, 0, 0, WHITE, "w/s --------> zoom in/out");
	mlx_string_put(e->mlx, e->win, 0, 12, WHITE, "arrow keys -> move");
	mlx_string_put(e->mlx, e->win, 0, 24, WHITE, "+/- --------> change height");
	if (e->size_i == 0 && e->size_j == 0)
		init_opt(e);
	while (++i < e->heigh - 1)
	{
		j = -1;
		while (++j < e->len - 1)
		{
			vert_line(e, i, j);
			hori_line(e, i, j);
		}
	}
}
