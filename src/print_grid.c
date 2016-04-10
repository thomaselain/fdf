/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:10:05 by telain            #+#    #+#             */
/*   Updated: 2016/03/28 22:45:19 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_grid(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (e->grid[++i])
	{
		j = -1;
		while (++j < e->len)
		{
			ft_putnbr(e->grid[i][j]);
			ft_putstr(" ");
		}
		ft_putstr("\n");
	}
}
