/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:03:43 by telain            #+#    #+#             */
/*   Updated: 2016/05/12 23:52:41 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define J j * e->size_j
#define JN (j + 1) * e->size_j
#define I i * e->size_i
#define IN (i + 1) * e->size_i

void	draw_grid(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->heigh - 1)
	{
		j = -1;
		while (++j < e->len - 1)
		{
/*
 * e->x1 = I + e->start[0];
			e->y1 = J + e->start[1];
			e->x2 = IN + e->start[0];
			e->y2 = J + e->start[1];	// Test pour dessiner la grille a plat.
			line(e);
			e->x1 = I + e->start[0];
			e->y1 = J + e->start[1];
			e->x2 = I + e->start[0];
			e->y2 = JN + e->start[1];
			line(e);
*/
			e->x1 = (I - J) + e->start[0];
			e->y1 = (I + J) / 3 + e->start[1] - e->grid[i][j] * 5;
			e->x2 = (I - JN) + e->start[0];
			e->y2 = (I + JN) / 3 + e->start[1] - e->grid[i][j + 1] * 5;
			line(e);					//Test pour la grille en isometrique.
			e->x1 = (I - J) + e->start[0];
			e->y1 = (I + J) / 3 + e->start[1] - e->grid[i][j] * 5;
			e->x2 = (IN - J) + e->start[0];
			e->y2 = (IN + J) / 3 + e->start[1] - e->grid[i + 1][j] * 5;
			line(e);


/*		
			e->x1 = e->start[0];
			e->y1 = e->start[1];		// Test pour les octants.
			e->x2 = 500;
			e->y2 = 500;
			line(e);
*/
		}
	}
}
