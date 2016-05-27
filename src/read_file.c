/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:43:49 by telain            #+#    #+#             */
/*   Updated: 2016/05/24 18:17:17 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_file_type(t_env *e)
{
	char	*line;
	int		i;

	e->fd = open(e->file, O_RDONLY, S_IREAD);
	while (get_next_line(e->fd, &line) > 0)
	{
		i = -1;
		while (line[++i])
		{
			if (ft_isalnum(line[i]) == 0 && line[i] != ' ')
			{
				ft_putstr("Wrong file, please choose a \".fdf\" file\n");
				exit (0);
			}
		}
	}
}

int		get_lengh(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[i])
	{
		while (ft_isalnum(line[i]) == 1 || line[i] == '-')
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
		while (ft_isalnum(line[i + len]) == 1 || line[i + len] == '-')
			len++;
		e->grid[n][j++] = ft_atoi(ft_strsub(line, i, len));
		len = 0;
		while ((line[i] <= '9' && line[i] >= '0') || line[i] == '-')
			i++;
		while (line[i] == ' ' || line[i] == '\n')
			i++;
	}
}

void	read_file(t_env *e)
{
	char	*line;
	int		n;

	n = 0;
	e->grid = (int**)ft_memalloc(sizeof(int*) * 500);
	//check_file_type(e);
	e->fd = open(e->file, O_RDONLY, S_IREAD);
	while (get_next_line(e->fd, &line) > 0)
	{
		e->len = get_lengh(line);
		e->grid[n] = (int*)ft_memalloc(sizeof(int) * (e->len + 1));
		create_grid(e, line, n++);
		e->heigh++;
		ft_putendl(line);
	}
	close(e->fd);
}
