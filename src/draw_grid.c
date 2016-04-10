/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:03:43 by telain            #+#    #+#             */
/*   Updated: 2016/04/10 15:01:09 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define J j * e->size_j
#define JN (j + 1) * e->size_j
#define I i * e->size_i
#define IN (i + 1) * e->size_i
/*
void	draw_grid(t_env *e) // Dessin carthesien
{
	int		i;
	int		j;
	int		ratio;
	int		tab;

	ratio = 4;
	tab = -3;
	i = 0;
	j = 0;
	while (i < e->heigh - 1)
	{

		while (j < e->len)
		{
			line(e->start[0] + i * e->size_i,                                   //x1
					e->start[1] + j * e->size_j - e->grid[i][j],                //y1
					e->start[0] + (i + 1) * e->size_i,                          //x2
					e->start[1] + (j) * e->size_j - e->grid[i + 1][j], e);      //y2
			line(e->start[0] + i * e->size_i,                                   //x1
					e->start[1] + j * e->size_j - e->grid[i][j],                //y1
					e->start[0] + i * e->size_i,                                //x2
					e->start[1] + (j + 1) * e->size_j - e->grid[i][j + 1], e);  //y2
			j++;
		}
		i++;
		j = 0;
	}
}
*/
void	draw_grid(t_env *e)   // Methode du site de Guillaume (Dessin isometrique)
{
	int		i;
	int		j;
	int		ratio;
	int		tab;

	i = 0;
	j = 0;
	while (i < e->heigh - 1)
	{

		while (j < e->len)
		{
//			line(I - J + e->start[0], (I + J) / 3 + e->start[1]/* - e->grid[i][j]*/,
//					(I - JN) + e->start[0], (I + JN) / 3 + e->start[1]/* - e->grid[i][j + 1]*/, e);
			line(I - J + e->start[0], (I + J) / 3 + e->start[1]/* - e->grid[i][j]*/,
					(IN - J) + e->start[0], (IN + J) / 3 + e->start[1]/* - e->grid[i + 1][j]*/, e);
			j++;
		}
		i++;
		j = 0;
	}
}

void	vert_line(int x1, int y1, int x2, int y2, t_env *e)
{
    float	x;
    float	a;
    float	b;
    float	y_start;
    float	y_end;
    
    y_start = (y1 < y2) ? y1 : y2;
    y_end = (y1 < y2) ? y2 : y1;
    a = (x2 - x1) / (y_end - y_start);
    b = x1 - a * y_start;
    x = a * y_start + b;
    while (y_start++ <= y_end)
    {
        mlx_pixel_put(e->mlx, e->win, (int)x, y_start, 0xFFFFFF);
        x = a * y_start + b;
    }
}

void	line(int x1, int y1, int x2, int y2, t_env *e)
{
    float	y;
    float	a;
    float	b;
    float	x_start;
    float	x_end;
    
    x_start = (x1 < x2) ? x1 : x2;
    x_end = (x1 < x2) ? x2 : x1;
    a = (y2 - y1) / (x_end - x_start);
    b = y1 - a * x_start;
    y = a * x_start + b;
    if (a > 1 || a < -1)
        vert_line(x1, y1, x2, y2, e);
    else
    {
        while (x_start++ <= x_end)
        {
            mlx_pixel_put(e->mlx, e->win, x_start, (int)y, 0xFFFFFF);
            y = a * x_start + b;
        }
    }
}
