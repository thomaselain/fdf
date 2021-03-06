/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:20:35 by telain            #+#    #+#             */
/*   Updated: 2016/06/01 14:42:18 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	oct_2(t_env *e, int dx, int dy, int color)
{
	int		f;

	f = dy;
	dy = f * 2;
	dx *= 2;
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, (int)e->x1, (int)e->y1, color);
		if (e->y1++ == e->y2)
			break ;
		if ((f -= dx) < 0)
		{
			e->x1++;
			f += dy;
		}
	}
}
