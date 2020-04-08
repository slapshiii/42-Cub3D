/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_param.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:50:41 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/08 14:55:10 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PARAM_H
# define PARSER_PARAM_H

# include <libft.h>

typedef struct  param_s
{
    int     res_w;
    int     res_h;
    char    *path_no;
    char    *path_so;
    char    *path_we;
    char    *path_ea;
    char    *path_sprite;
    int     color_floor;
    int     color_ceiling;
    char    **map;
}               param_t;



#endif
