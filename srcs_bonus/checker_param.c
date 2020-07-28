/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 19:45:35 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/28 04:43:49 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/parser_param.h"
#include <stdio.h>

int	handle_color(char *rgb)
{
	int res;

	if (ft_atoi(rgb) < 0 || ft_atoi(rgb) > 255)
		return (0);
	res = ft_atoi(rgb) << 16;
	if (ft_atoi(ft_strchr(rgb, ',') + 1) < 0
		|| ft_atoi(ft_strchr(rgb, ',') + 1) > 255)
		return (0);
	res += ft_atoi(ft_strchr(rgb, ',') + 1) << 8;
	if (ft_atoi(ft_strrchr(rgb, ',') + 1) < 0
		|| ft_atoi(ft_strrchr(rgb, ',') + 1) > 255)
		return (0);
	res += ft_atoi(ft_strrchr(rgb, ',') + 1);
	return (res);
}

int	check_map_valid(param_t *p)
{
	int x;
	int y;

	y = -1;
	p->max_x = 0;
	while (p->map[++y])
	{
		x = -1;
		while (p->map[y][++x])
		{
			if (p->map[y][x] == '2')
				p->num_sprite++;
			if (!(ft_strchr("012 NSWE", p->map[y][x])))
				return (1);
			if (check_close_map(p->map, x, y) == 1)
				return (1);
			if (check_spawn(p->map, x, y, p) == 1)
				return (1);
		}
		p->max_x = ((int)x > p->max_x) ? x : p->max_x;
	}
	p->max_y = y;
	return (0);
}

int	check_param(char **split, param_t *p)
{
	if (ft_strncmp(split[0], "R", 1) == 0 && !p->res_h)
	{
		if ((p->res_w = ft_atoi(split[1])) < 0
			|| (p->res_h = ft_atoi(split[2])) < 0)
			return (0);
	}
	else if (ft_strncmp(split[0], "NO", 2) == 0 && !p->path_no)
		p->path_no = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "SO", 2) == 0 && !p->path_so)
		p->path_so = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "WE", 2) == 0 && !p->path_we)
		p->path_we = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "EA", 2) == 0 && !p->path_ea)
		p->path_ea = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "S", 1) == 0 && !p->path_sprite)
		p->path_sprite = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "C", 1) == 0 && !p->color_ceiling)
		p->color_ceiling = handle_color(split[1]);
	else if (ft_strncmp(split[0], "F", 1) == 0 && !p->color_floor)
		p->color_floor = handle_color(split[1]);
	else
		return (0);
	return (1);
}

int	check_map(char **tab, param_t *p, int offset, int max)
{
	if (ft_strchr(" 1", tab[offset][0]))
	{
		if (!p->map && (p->map =
			(char**)malloc(sizeof(char*) * (max - offset + 2))))
		{
			bzero(p->map, sizeof(char*) * (max - offset + 2));
			while (offset <= max)
			{
				p->map[max - offset] = ft_strdup(tab[max]);
				max--;
			}
			if (check_map_valid(p))
				return (0);
			return (1);
		}
	}
	return (0);
}

int	check_config(param_t *p)
{
	int i;
	int j;
	int k;

	k = 0;
	i = -1;
	if (!p->res_h || !p->res_w || !p->path_no || !p->path_so || !p->path_we
		|| !p->path_ea || !p->path_sprite || !p->color_floor
		|| !p->color_ceiling || !p->map || !p->spawn_dir
		|| !(p->sprite = (sprite_t*)malloc(sizeof(sprite_t) * p->num_sprite)))
		return (1);
	bzero(p->sprite, sizeof(sprite_t) * p->num_sprite);
	while (p->map[++i])
	{
		j = -1;
		while (p->map[i][++j])
			if (p->map[i][j] == '2')
			{
				p->sprite[k].pos = (coord_t){j, i};
				p->sprite[k].id = k;
				k++;
			}
	}
	return (0);
}
