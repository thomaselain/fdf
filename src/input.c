/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 17:38:26 by telain            #+#    #+#             */
/*   Updated: 2016/06/02 17:57:06 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		find_key(int key, t_env *e)
{
	if (key == 126 || key == 125 || key == 124 || key == 123 || key == 13 ||
			key == 1 || key == 14 || key == 2 || key == 53 || key == 78 ||
			key == 69)
		move(key, e);
	clear(e);
	return (key);
}

void	move(int key, t_env *e)
{
	if (key == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	(key == 123) ? e->start[0] += 20 : key;
	(key == 124) ? e->start[0] -= 20 : key;
	(key == 125) ? e->start[1] -= 20 : key;
	(key == 126) ? e->start[1] += 20 : key;
	(key == 78) ? e->height-- : key;
	(key == 69) ? e->height++ : key;
	(key == 13) ? e->size_i += 1 : key;
	(key == 13) ? e->size_j -= 1 : key;
	(key == 13) ? e->start[0] -= 15 : key;
	(key == 1) ? e->size_i -= 1 : key;
	(key == 1) ? e->size_j += 1 : key;
	(key == 1) ? e->start[0] += 15 : key;
}
