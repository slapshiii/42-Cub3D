/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:57 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/07 13:23:42 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/parser_param.h"
#include "../get_next_line/get_next_line.h"
#include "../include_bonus/cub3d.h"

int	check_file(char **tab, int index, t_game *g)
{
	int		i;
	char	**split;
	int		res;

	i = 0;
	while (i <= index)
	{
		split = ft_split(tab[i], ' ');
		if (split)
		{
			res = 1;
			if (split[0] && (res = check_param(split, g->p)))
				res = 1;
			else if (res == 0 && (res = check_map(tab, g->p, i, index)))
				index = 0;
		}
		clear_tab(split, 0);
		if (res == 0)
			return (1);
		i++;
	}
	return (0);
}

int	parser_param(t_game *g, char *path)
{
	char	*temp[255];
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(path, O_RDONLY)) >= 0)
		if ((g->p = (t_param*)malloc(sizeof(t_param))))
		{
			ft_bzero(g->p, sizeof(t_param));
			while (get_next_line(fd, &temp[i]) > 0)
				i++;
			if (check_file(temp, i, g) == 0)
			{
				clear_tab(temp, i);
				if (check_config(g->p))
					return (1);
				return (0);
			}
			clear_tab(temp, i);
		}
	return (1);
}

int	check_close_map(char **map, int x, int y)
{
	if (ft_strchr("02NSWE", map[y][x])
					&& (y == 0 || x == 0
						|| x == (int)(ft_strlen(map[y]) - 1) || map[y + 1] == 0
						|| ft_strchr(" \0", map[y + 1][x])
						|| ft_strchr(" \0", map[y - 1][x])
						|| ft_strchr(" \0", map[y][x - 1])
						|| ft_strchr(" \0", map[y][x - 1])))
		return (1);
	return (0);
}

int	check_spawn(char **map, int x, int y, t_param *p)
{
	if (ft_strchr("NSWE", map[y][x]))
	{
		if (p->spawn_x != 0)
			return (1);
		else
		{
			p->spawn_dir = p->map[y][x];
			p->spawn_x = x;
			p->spawn_y = y;
		}
	}
	return (0);
}
