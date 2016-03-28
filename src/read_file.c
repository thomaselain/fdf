/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:43:49 by telain            #+#    #+#             */
/*   Updated: 2016/03/28 16:57:54 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_lengh(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[i])
	{
		while (line[i + len] != ' ')
			i++;
		len++;
		while (line[i] == ' ')
			i++;
	}
	return (len);
}

void	create_grid(t_env *e, char *line, int n)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	j = 0;
	while (line[i])
	{
		while (line[i + len] != ' ')
			len++;
		e->grid[n][j] = ft_atoi(ft_strsub(line, i, len));
		ft_putnbr(e->grid[n][j]);
		ft_putchar(' ');
		len = 0;
		j++;
		while (line[i] <= '9' && line[i] >= '0')
			i++;
		while (line[i] == ' ' || line[i] == '\n')
			i++;
	}
	ft_putstr("\n");
}

void	read_file(t_env *e)
{
	char	**pline;
	char	*line;
	int		i;
	int		n;
//	int		len;

	i = 0;
	n = 0;
//	len = 0;
	pline = &line;
//	while (get_next_line(e->fd, pline) > 0)
//		len++;
	e->grid = (int**)ft_memalloc(sizeof(int*) * (50 /*len - 1*/));
//	closei(e->fd);
	e->fd = open(e->file, O_RDONLY, S_IREAD);
	get_next_line(e->fd, pline);
	e->len = get_lengh(line);
	while (get_next_line(e->fd, pline) > 0)
	{
		e->grid[n] = (int*)ft_memalloc(sizeof(int) * (e->len + 1));
		create_grid(e, line, n);
		n++;
		e->heigh++;
	}
	i = 0;
}
