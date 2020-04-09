/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 19:45:35 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/09 15:08:49 by phnguyen         ###   ########.fr       */
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

int check_param(char **split, param_t *p)
{
    printf("%s - %s\n", split[0], split[1]);
    if(ft_strncmp(split[0], "R", 1) && !p->res_h)
    {
        p->res_w = ft_atoi(split[1]);
        p->res_h = ft_atoi(split[2]);
    }
    else if(ft_strncmp(split[0], "NO", 2) && !p->path_no)
        p->path_no = ft_strdup(split[1]);
    else if(ft_strncmp(split[0], "SO", 2) && !p->path_so)
        p->path_so = ft_strdup(split[1]);
    else if(ft_strncmp(split[0], "WE", 2) && !p->path_we)
        p->path_we = ft_strdup(split[1]);
    else if(ft_strncmp(split[0], "EA", 2) && !p->path_ea)
        p->path_ea = ft_strdup(split[1]);
    else if(ft_strncmp(split[0], "S", 1) && !p->path_sprite)
        p->path_sprite = ft_strdup(split[1]);
    else if(ft_strncmp(split[0], "C", 1) && !p->color_ceiling)
        p->color_ceiling = handle_color(split[1]);
    else if(ft_strncmp(split[0], "F", 1) && !p->color_floor)
        p->color_floor = handle_color(split[1]);
    else
        return (0);
    return (1);
}

int check_map(char **tab, param_t *p, int offset)
{
    p->map = tab;
    return (offset);
}

int check_config(param_t *p)
{
    (void)p;
    return (0);
}