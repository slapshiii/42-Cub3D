/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:40:48 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/07 12:43:49 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	save_bitmap(t_game *g)
{
	int		fd;
	int		i;
	char	*filename;

	i = 0;
	if (!(filename = ft_strdup("./bitmap.bmp")))
		error_exit("no malloc\n", g);
	while (exists(filename) == 0)
	{
		ft_strlcpy(filename, "bitmap_0.bmp", 13);
		filename[7] += i;
		i++;
	}
	if ((fd = open(filename, O_RDWR | O_TRUNC)) == -1)
	{
		free(filename);
		error_exit("open failed\n", g);
	}
	free(filename);
	if (screenshot(g, fd) != 0)
		error_exit("Screenshot failed\n", g);
	error_exit("Screened\n", g);
}

int		exists(const char *fname)
{
	int fd;

	if ((fd = open(fname, O_CREAT | O_EXCL, 00777)) > 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int		screenshot(t_game *g, int fd)
{
	t_save temp;

	temp = (t_save){(54 + 4 * g->p->res_w * g->p->res_h), 54, 40, 1, 32, 0};
	write(fd, "BM", 2);
	write(fd, &temp.size, sizeof(int));
	write(fd, &temp.unused, sizeof(int));
	write(fd, &temp.offset, sizeof(int));
	write(fd, &temp.header_bytes, sizeof(int));
	write(fd, &g->p->res_w, sizeof(int));
	write(fd, &g->p->res_h, sizeof(int));
	write(fd, &temp.plane, sizeof(short int));
	write(fd, &temp.bpixel, sizeof(short int));
	write(fd, &temp.unused, sizeof(int));
	write(fd, &temp.unused, sizeof(int));
	write(fd, &temp.unused, sizeof(int));
	write(fd, &temp.unused, sizeof(int));
	write(fd, &temp.unused, sizeof(int));
	write(fd, &temp.unused, sizeof(int));
	write_texture_bmp_file(g, fd);
	close(fd);
	return (0);
}

void	write_texture_bmp_file(t_game *g, int fd)
{
	int	x;
	int	y;
	int width;

	y = 0;
	while (y < g->p->res_h)
	{
		x = 0;
		width = ((g->p->res_w) * (g->p->res_h - y - 1));
		while (x < g->p->res_w)
		{
			write(fd, &g->win_img.data[width], 4);
			width++;
			x++;
		}
		y++;
	}
}
