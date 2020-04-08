/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:39:15 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/08 17:22:24 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parser_param.h"
# include "libft.h"
# include "struct.h"

void    error_exit(char *msg, game_t *g);
void    ft_game(game_t *g, int screen, char *path);

#endif
