/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 02:10:44 by telain            #+#    #+#             */
/*   Updated: 2016/05/13 00:03:27 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move(int key, t_env *e)
{
	(key == 123) ? e->start[0] -= 20 : key;
	(key == 124) ? e->start[0] += 20 : key;
	(key == 125) ? e->start[1] += 20 : key;
	(key == 126) ? e->start[1] -= 20 : key;
	(key == 13) ? e->size_i += 1 : key;
	(key == 13) ? e->size_j -= 1 : key;
	(key == 1) ? e->size_i -= 1 : key;
	(key == 1) ? e->size_j += 1 : key;
	if (key == 53)
		exit (0);
}

void	clear(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
}

int		find_key(int key, t_env *e)
{
	if (key == 126 || key == 124 || key == 125 || key == 123 || key == 13 ||
			key == 1 || key == 14 || key == 2 || key == 53)
		move(key, e);
	clear(e);
	return (key);
}

int		draw(int keycode, void *e)
{
	ft_putstr("Keycode : ");
	ft_putnendl(keycode);
	find_key(keycode, e);
	draw_grid(e); 
	return (0);
}

void	new_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1100, 1100, "Fdf_42");
	e->len = 0;
	e->heigh = 0;
	e->lines = 0;
	e->start[0] = 50;
	e->start[1] = 450;
	e->size_i = 18;
	e->size_j = -18;
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
		ft_putstr(" <filename> [size]\n");
		return (0);
	}
	new_env(&e);
	e.file = av[1];
	e.fd = open(e.file, O_RDONLY, S_IREAD);
	read_file(&e);
	draw(0, &e);
	mlx_key_hook(e.win, draw, &e);
//	mlx_expose_hook(e.win, draw, &e);
	mlx_loop(e.mlx);
	return (0);
}
