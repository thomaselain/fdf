/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:54:55 by telain            #+#    #+#             */
/*   Updated: 2016/05/12 18:39:08 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		line(t_env *e)
{
	int		dx;
	int		dy;

	if ((dx = e->x2 - e->x1) != 0)
	{
		if (dx > 0)
		{
			if ((dy = e->y2 - e->y1) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
                        oct_1(e, dx, dy);
					else
                        oct_2(e, dx, dy);
				}
				else
				{
					if (dx >= -dy)
                        oct_8(e, dx, dy);
					else
                        oct_7(e, dx, dy);
				}
			}
			else
			{
				while (e->x1++ != e->x2)
					mlx_pixel_put(e->mlx, e->win, (int)e->x1, (int)e->y1, 0xFFFFFF);
			}
		}
		else
		{
			if ((dy = e->y2 - e->y1) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
                        oct_4(e, dx, dy);
					else
                        oct_3(e, dx, dy);
				}
				else
				{
					if (dx <= dy)
                        oct_5(e, dx, dy);
                    else
                        oct_6(e, dx, dy);
				}
			}
			else
			{
				while (e->x1-- != e->x2)
					mlx_pixel_put(e->mlx, e->win, (int)e->x1, (int)e->y1, 0xFFFFFF);
			}
		}
	}
	else
	{
		if ((dy = e->y2 - e->y1) != 0)
		{
			if (dy > 0)
			{
				while (e->y1++ != e->y2)
					mlx_pixel_put(e->mlx, e->win, (int)e->x1, (int)e->y1, 0xFFFFFF);
			}
			else
			{
				while (e->y1-- != e->y2)
					mlx_pixel_put(e->mlx, e->win, (int)e->x1, (int)e->y1, 0xFFFFFF);
			}
		}
	}
}
