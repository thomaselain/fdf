/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:20:35 by telain            #+#    #+#             */
/*   Updated: 2016/05/12 17:58:15 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	oct_6(t_env *e, int dx, int dy)
{
    int		f;
 
    dy = (f = dy) * 2;
    dx *= 2;
    while (42)
    {
        mlx_pixel_put(e->mlx, e->win, (int)e->x1, (int)e->y1, 0xFFFFFF);
        if (e->y1-- == e->y2)
            break ;
        if ((f -= dx) >= 0)
        {
            e->x1--;
            f += dy;
        }
    }
}