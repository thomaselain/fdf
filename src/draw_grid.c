/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:03:43 by telain            #+#    #+#             */
/*   Updated: 2016/05/27 18:23:46 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		choose_color(int h)
{
	int		color;

	color =  0x000000;
	color = (h <= 0) ? 0x0000ff : color;
	color = (h <= 5) ? 0x00ff00 : color;
	color = (h <= 15) ? 0xa5a2a2 : color;
	return (color);
}

void	write_opt(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 0, 0, 0xffffff, "w ----------> zoom in");
	mlx_string_put(e->mlx, e->win, 0, 10, 0xffffff, "s ----------> zoom out");
	mlx_string_put(e->mlx, e->win, 0, 20, 0xffffff, "arrow keys -> move");
}

void	draw_grid(t_env *e)
{
	int		i;
	int		j;

    i = -1;
	write_opt(e);
    if (e->size_i == 0 && e->size_j == 0)
    {
        e->size_i = WIN_X / (e->len * 1.5);
        e->size_j = -e->size_i;
        e->start[0] = -e->len + e->size_i * 2;
        e->start[1] = 400;
    }
	while (++i < e->heigh - 1)
	{
		j = -1;
		while (++j < e->len - 1)
		{
			e->x1 = (I - J) + e->start[0];
			e->y1 = (I + J) / 3 + e->start[1] - e->grid[i][j] * 3;
			e->x2 = (I - JN) + e->start[0];
			e->y2 = (I + JN) / 3 + e->start[1] - e->grid[i][j + 1] * 3;
			line(e, choose_color(e->grid[i][j]));
			e->x1 = (I - J) + e->start[0];
			e->y1 = (I + J) / 3 + e->start[1] - e->grid[i][j] * 3;
			e->x2 = (IN - J) + e->start[0];
			e->y2 = (IN + J) / 3 + e->start[1] - e->grid[i + 1][j] * 3;
			line(e, choose_color(e->grid[i][j]));
		}
	}
}
