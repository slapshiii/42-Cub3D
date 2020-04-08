/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:26:04 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/08 15:48:23 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void    error_exit(const char *msg, game_t *g);

void    error_exit(const char *msg, game_t *g)
{
    ft_putstr_fd(msg, 2);
    exit(1);
}