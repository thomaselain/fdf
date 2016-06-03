/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:54:55 by telain            #+#    #+#             */
/*   Updated: 2016/06/03 16:51:48 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		line(t_env *e, int color)
{
	int		dx;
	int		dy;

	dy = 0;
	if ((dx = e->x2 - e->x1) != 0)
	{
		if (dx > 0)
			line2(e, color, dx, dy);
		else
			line3(e, color, dx, dy);
	}
	else
	{
		if ((dy = e->y2 - e->y1) != 0)
			line4(e, color, dx, dy);
	}
}

void		line2(t_env *e, int color, int dx, int dy)
{
	if ((dy = e->y2 - e->y1) != 0)
	{
		if (dy > 0)
		{
			if (dx >= dy)
				oct_1(e, dx, dy, color);
			else
				oct_2(e, dx, dy, color);
		}
		else
		{
			if (dx >= -dy)
				oct_8(e, dx, dy, color);
			else
				oct_7(e, dx, dy, color);
		}
	}
	else
	{
		while (e->x1++ != e->x2)
			mlx_pixel_put(e->mlx, e->win, (int)e->x1, (int)e->y1, color);
	}
}

void		line3(t_env *e, int color, int dx, int dy)
{
	if ((dy = e->y2 - e->y1) != 0)
	{
		if (dy > 0)
		{
			if (-dx >= dy)
				oct_4(e, dx, dy, color);
			else
				oct_3(e, dx, dy, color);
		}
		else
		{
			if (dx <= dy)
				oct_5(e, dx, dy, color);
			else
				oct_6(e, dx, dy, color);
		}
	}
	else
	{
		while (e->x1-- != e->x2)
			mlx_pixel_put(e->mlx, e->win, (int)e->x1, (int)e->y1, color);
	}
}

void		line4(t_env *e, int color, int dx, int dy)
{
	dx = 0;
	if (dy > 0)
	{
		while (e->y1++ != e->y2)
			mlx_pixel_put(e->mlx, e->win, (int)e->x1, (int)e->y1, color);
	}
	else
	{
		while (e->y1-- != e->y2)
			mlx_pixel_put(e->mlx, e->win, (int)e->x1, (int)e->y1, color);
	}
}
