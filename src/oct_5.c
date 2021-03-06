/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:20:35 by telain            #+#    #+#             */
/*   Updated: 2016/06/01 14:43:00 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	oct_5(t_env *e, int dx, int dy, int color)
{
	int		f;

	f = dx;
	dx = f * 2;
	dy *= 2;
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, (int)e->x1, (int)e->y1, color);
		if (e->x1-- == e->x2)
			break ;
		if ((f -= dy) >= 0)
		{
			e->y1--;
			f += dx;
		}
	}
}
