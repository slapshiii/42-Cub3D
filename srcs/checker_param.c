/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 19:45:35 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/09 21:51:24 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_param.h"
#include <stdio.h>

int handle_color(char *rgb)
{
    int res;

    res = ft_atoi(rgb)<<16;
    res += ft_atoi(ft_strchr(rgb, ',') + 1)<<8;
    res += ft_atoi(ft_strrchr(rgb, ',') + 1);
    return (res);
}

int check_map_valid(param_t *p)
{
    unsigned int x;
    unsigned int y;

    y = 0;
    while(p->map[y])
    {
        x = 0;
        while(p->map[y][x])
        {
            if(!(ft_strchr("012 NSWE", p->map[y][x])))
                return(1);
            if(ft_strchr("02NSWE", p->map[y][x])
                && (y == 0 || x == 0
                || x == (ft_strlen(p->map[y]) - 1) || p->map[y + 1] == 0
                || !ft_strchr("012NSWE", p->map[y + 1][x + 1])
                || !ft_strchr("012NSWE", p->map[y - 1][x + 1])
                || !ft_strchr("012NSWE", p->map[y + 1][x - 1])
                || !ft_strchr("012NSWE", p->map[y - 1][x - 1])))
                return(1);
            x++;
        }
        y++;
    }
    return(0);
}

int check_param(char **split, param_t *p)
{
    if(ft_strncmp(split[0], "R", 1) == 0 && !p->res_h)
    {
        p->res_w = ft_atoi(split[1]);
        p->res_h = ft_atoi(split[2]);
    }
    else if(ft_strncmp(split[0], "NO", 2) == 0 && !p->path_no)
        p->path_no = ft_strdup(split[1]);
    else if(ft_strncmp(split[0], "SO", 2) == 0 && !p->path_so)
        p->path_so = ft_strdup(split[1]);
    else if(ft_strncmp(split[0], "WE", 2) == 0 && !p->path_we)
        p->path_we = ft_strdup(split[1]);
    else if(ft_strncmp(split[0], "EA", 2) == 0 && !p->path_ea)
        p->path_ea = ft_strdup(split[1]);
    else if(ft_strncmp(split[0], "S", 1) == 0 && !p->path_sprite)
        p->path_sprite = ft_strdup(split[1]);
    else if(ft_strncmp(split[0], "C", 1) == 0 && !p->color_ceiling)
        p->color_ceiling = handle_color(split[1]);
    else if(ft_strncmp(split[0], "F", 1) == 0 && !p->color_floor)
        p->color_floor = handle_color(split[1]);
    else
        return (0);
    return (1);
}

int check_map(char **tab, param_t *p, int offset, int max)
{
    if (ft_strchr(" 1", tab[offset][0]))
    {
        if (!p->map && (p->map = (char**)malloc(sizeof(char*) * (max - offset + 2))))
        {
            bzero(p->map, sizeof(char*) * (max - offset + 2)); //C4EST ICI QUE J4INITIALISE
            while(offset <= max)
            {
                p->map[max - offset] = ft_strdup(tab[max]);
                max--;
            }
            if(check_map_valid(p))
                return (0);
            return (1);
        }
    }
    return (0);
}

int check_config(param_t *p)
{
    if (!p->res_h || !p->res_w
    || !p->path_no || !p->path_so || !p->path_we || !p->path_ea
    || !p->path_sprite || !p->color_floor || !p->color_ceiling
    || !p->map)
        return(1);
    return (0);
}