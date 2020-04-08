/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:26:04 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/08 17:17:12 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser_param.h"

void    error_exit(char *msg, game_t *g)
{
    ft_putstr_fd(msg, 2);
    if(g)
        exit(1);
    exit(1);
}