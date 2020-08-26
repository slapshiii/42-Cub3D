/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:59 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/26 22:34:06 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/libft_bonus.h"

/*
**void	end(void) __attribute__((destructor));
*/
int	main(int ac, char **av)
{
	t_game	*g;
	int		screen;

	screen = 0;
	if (!(g = (t_game*)malloc(sizeof(t_game))))
		error_exit("Error: Could'n malloc.\n", g);
	bzero(g, sizeof(t_game));
	if (ac == 3 && (ft_strncmp(av[2], "--save", 7) == 0))
		screen = 1;
	if (ac == (2 + screen))
		ft_game(g, screen, av[1]);
	else
		error_exit("Error: Too much/Too few argument.\n", g);
	exit(0);
}

/*
**void	end(void)
**{
**	system("leaks Cub3D");
**}
*/
