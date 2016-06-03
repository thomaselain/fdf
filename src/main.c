/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 02:10:44 by telain            #+#    #+#             */
/*   Updated: 2016/06/03 13:30:07 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clear(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
}

int		draw(int keycode, void *e)
{
	find_key(keycode, e);
	draw_grid(e);
	return (0);
}

void	new_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fdf_42");
	e->len = 0;
	e->heigh = 0;
	e->lines = 0;
	e->start[0] = 0;
	e->start[1] = 0;
	e->size_i = 0;
	e->size_j = 0;
}

int		main(int ac, char **av)
{
	t_env	e;
	int		i;

	i = 0;
	if (ac < 2)
	{
		ft_putstr("Usage : ");
		ft_putstr(av[0]);
		ft_putstr(" <filename> [size_z]\n");
		return (0);
	}
	new_env(&e);
	e.file = av[1];
	e.fd = open(e.file, O_RDONLY, S_IREAD);
	read_file(&e);
	draw(0, &e);
	mlx_key_hook(e.win, draw, &e);
	mlx_loop(e.mlx);
	return (0);
}
